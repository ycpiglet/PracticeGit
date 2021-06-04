#include "Win32Window.h"
#include <mutex>
#include <sstream>
#include <string>
#include <functional>
#include <utility>

using namespace StandardCppWin32App1;

namespace StandardCppWin32App1 {
	const int Win32WindowPtrWindowDataByteOffset = 0;

	LPCWSTR Win32WindowClassName = L"Win32WindowClass";
	
#ifdef _DEBUG
	::std::once_flag debugMessageBoxNoWindowProcOnceFlag;
#endif

	LRESULT CALLBACK StandaloneWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
		LONG_PTR objPtr = GetWindowLongPtrW(hwnd, Win32WindowPtrWindowDataByteOffset);

		if (objPtr == 0) {
			return DefWindowProcW(hwnd, msg, wparam, lparam);
		}
		else {
			auto wndprocPtr = reinterpret_cast<Win32Window*>(objPtr)->m_windowProc;
			if (wndprocPtr != nullptr) {
				return wndprocPtr(hwnd, msg, wparam, lparam);
			}
			else {
#ifdef _DEBUG
				::std::call_once(debugMessageBoxNoWindowProcOnceFlag, &MessageBoxW, hwnd, L"The Win32Window was created with a null Window Procedure.", L"Null WndProc", MB_OK);
#endif
				return DefWindowProcW(hwnd, msg, wparam, lparam);
			}
		}
	}

	ATOM RegisterWin32WindowClass(HINSTANCE hInstance) {
		WNDCLASSEX wcex{ };

		wcex.cbSize = sizeof(WNDCLASSEX);
		// We want CS_HREDRAW and CS_VREDRAW so we get a refresh of the whole window if the client area changes due to movement or size adjustment.
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = StandaloneWindowProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = sizeof(Win32Window*);
		wcex.hInstance = hInstance;
		wcex.hIcon = nullptr;
		wcex.hCursor = LoadCursorW(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = Win32WindowClassName;
		wcex.hIconSm = nullptr;

		return RegisterClassEx(&wcex);
	}

	::std::once_flag registerWin32WindowClassOnceFlag;
}

Win32Window::Win32Window(WNDPROC lpfnWndProc, LPCWSTR windowName, HMENU hMenu, DWORD style, DWORD extendedStyle, int width, int height, int x, int y, LPCWSTR lpClassName, HWND parent, HINSTANCE hInstance, LPVOID lpParam)
	: m_hwnd(nullptr)
	, m_windowProc(lpfnWndProc) {
	if (hMenu == nullptr && ((style & WS_SYSMENU) != 0)) {
		throw ::std::invalid_argument("You must pass a valid hMenu argument if you are using a window style (such as WS_OVERLAPPEDWINDOW) that includes WS_SYSMENU. Either add a menu or use a style (such as WS_OVERLAPPED) which does not include WS_SYSMENU.");
	}

	::std::call_once(registerWin32WindowClassOnceFlag, &RegisterWin32WindowClass, WinMainParameters::GetHInstance());

	m_hwnd = ::CreateWindowExW(
		extendedStyle,
		lpClassName,
		windowName,
		style,
		x,
		y,
		width,
		height,
		parent,
		hMenu,
		hInstance,
		lpParam);

	if (m_hwnd == nullptr) {
		DWORD lastError = GetLastError();
		::std::stringstream errMsg;
		errMsg << "Failed call to CreateWindowEx in Win32Window constructor: GetLastError returned '" << lastError << "'.";
		throw ::std::logic_error(errMsg.str());
	}

	SetLastError(ERROR_SUCCESS);
	// Set in the "extra" bytes the pointer to the 'this' pointer
	// so it can handle messages for itself.
	if (!SetWindowLongPtrW(m_hwnd, Win32WindowPtrWindowDataByteOffset, (LONG_PTR)this)) {
		DWORD lastError = GetLastError();
		if (lastError != ERROR_SUCCESS) {
			::std::stringstream errMsg;
			errMsg << "Failed call to SetWindowLongPtrW(HWND, int, LONG_PTR) in Win32Window constructor: GetLastError returned '" << lastError << "'.";
			throw ::std::runtime_error(errMsg.str());
		}
	}

	// Initially display the window
	ShowWindow(m_hwnd, WinMainParameters::GetNCmdShow());
	UpdateWindow(m_hwnd);
}

Win32Window::~Win32Window() {
	if (m_hwnd != nullptr) {
		DestroyWindow(m_hwnd);
		m_hwnd = nullptr;
	}
}

int Win32Window::Join() {
	MSG msg{ };
	msg.message = WM_NULL;
	BOOL getMessageResult = FALSE;
	while (msg.message != WM_QUIT) {
		if ((getMessageResult = GetMessageW(&msg, nullptr, 0, 0)) != FALSE) {
			if (getMessageResult == -1) {
				DWORD lastError = GetLastError();
				::std::stringstream errMsg;
				errMsg << "Failed call to GetMessageW in Win32Window::Join: GetLastError returned '" << lastError << "'.";
				throw ::std::runtime_error(errMsg.str());
			}
			else {
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
		}
	}
	return (int)msg.wParam;
}

template <class Fn, class... Args>
int Win32Window::Join(Fn&& noMsgFn, Args&&... noMsgFnArgs) {
	MSG msg{ };
	msg.message = WM_NULL;
	while (msg.message != WM_QUIT) {
		if (!PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
			::std::invoke(noMsgFn, noMsgFnArgs);
		}
		else {
			if (msg.message != WM_QUIT) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}
	return (int)msg.wParam;
}

int Win32Window::Join(HACCEL accelTable) {
	if (accelTable == nullptr) {
#ifdef _DEBUG
		MessageBoxW(m_hwnd, L"Win32Window::Join was called with a null HACCEL.", L"Null HACCEL", MB_OK);
#endif
		return Join();
	}
	
	MSG msg{ };
	msg.message = WM_NULL;
	BOOL getMessageResult = FALSE;
	while (msg.message != WM_QUIT) {
		if ((getMessageResult = GetMessageW(&msg, nullptr, 0, 0)) != FALSE) {
			if (getMessageResult == -1) {
				DWORD lastError = GetLastError();
				::std::stringstream errMsg;
				errMsg << "Failed call to GetMessageW in Win32Window::Join: GetLastError returned '" << lastError << "'.";
				throw ::std::runtime_error(errMsg.str());
			}
			else {
				if (!TranslateAcceleratorW(msg.hwnd, accelTable, &msg)) {
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		}
	}
	return (int)msg.wParam;
}

template <class Fn, class... Args>
int Win32Window::Join(HACCEL accelTable, Fn&& noMsgFn, Args&&... noMsgFnArgs) {
	if (accelTable == nullptr) {
#ifdef _DEBUG
		MessageBoxW(m_hwnd, L"Win32Window::Join was called with a null HACCEL.", L"Null HACCEL", MB_OK);
#endif
		return Join(::std::forward(noMsgFn), ::std::forward(noMsgFnArgs));
	}
	
	MSG msg{ };
	msg.message = WM_NULL;
	while (msg.message != WM_QUIT) {
		if (!PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
			::std::invoke(noMsgFn, noMsgFnArgs);
		}
		else {
			if (msg.message != WM_QUIT) {
				if (!TranslateAcceleratorW(msg.hwnd, accelTable, &msg)) {
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		}
	}
	return (int)msg.wParam;
}
