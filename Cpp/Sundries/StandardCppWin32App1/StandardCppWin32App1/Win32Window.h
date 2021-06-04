#pragma once

#include "IncludeWindows.h"
#include "WinMainParameters.h"
#include <stdexcept>

namespace StandardCppWin32App1 {
	LRESULT CALLBACK StandaloneWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	extern LPCWSTR Win32WindowClassName;

	class Win32Window {
		friend LRESULT CALLBACK StandaloneWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		HWND m_hwnd = nullptr;
		WNDPROC m_windowProc = nullptr;
	public:
		Win32Window(WNDPROC lpfnWndProc, LPCWSTR windowName = nullptr, HMENU hMenu = nullptr, DWORD style = WS_OVERLAPPEDWINDOW, DWORD extendedStyle = 0UL, int width = CW_USEDEFAULT, int height = CW_USEDEFAULT, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, LPCWSTR lpClassName = Win32WindowClassName, HWND parent = nullptr, HINSTANCE hInstance = nullptr, LPVOID lpParam = nullptr);

		// Move only.
		Win32Window(const Win32Window&) = delete;
		Win32Window& operator=(const Win32Window&) = delete;
		Win32Window(Win32Window&&) = default;
		Win32Window& operator=(Win32Window&&) = default;

		~Win32Window();

		int Join();
		template <class Fn, class... Args>
		int Join(Fn&& noMsgFn, Args&&... noMsgFnArgs);
		int Join(HACCEL accelTable);
		template <class Fn, class... Args>
		int Join(HACCEL accelTable, Fn&& noMsgFn, Args&&... noMsgFnArgs);
	};
}
