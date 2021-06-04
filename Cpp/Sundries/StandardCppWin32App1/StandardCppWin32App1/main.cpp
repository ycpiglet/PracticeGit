#include "IncludeWindows.h"
#include "WinMainParameters.h"
#include "resource.h"
#include "Win32Window.h"
#include <stdexcept>
#include <string>
#include <sstream>

using namespace StandardCppWin32App1;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

// ISO C++ conformant entry point. The project properties explicitly sets this as the entry point in the manner
// documented for the linker's /ENTRY option: http://msdn.microsoft.com/en-us/library/f9t8842e.aspx . As per
// the documentation, the value set as the entry point is "mainCRTStartup", not "main". Every C or C++ program
// must perform any initialization required by the language standards before it begins executing our code. In
// Visual C++, this is done by the *CRTStartup functions, each of which goes on to call the developer's entry
// point function.
int main(int argc, char* argv[]) {
	MSG msg{ };
	msg.message = WM_NULL;
	HINSTANCE hInstance = WinMainParameters::GetHInstance();

	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	const int maxLoadString = 100;
	WCHAR appTitle[maxLoadString];	// The title bar text
	LoadStringW(hInstance, IDS_APP_TITLE, appTitle, maxLoadString);
	
	HMENU hMenu = nullptr;
	hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDC_STANDARDCPPWIN32APP1));

	if (hMenu == nullptr) {
		DWORD lastError = GetLastError();
		::std::stringstream errMsg;
		errMsg << "Failed call to LoadMenu in main: GetLastError returned '" << lastError << "'.";
		throw ::std::logic_error(errMsg.str());
	}

	HACCEL hAccelTable = nullptr;
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_STANDARDCPPWIN32APP1));

	if (hAccelTable == nullptr) {
		DWORD lastError = GetLastError();
		::std::stringstream errMsg;
		errMsg << "Failed call to LoadAccelerators in main: GetLastError returned '" << lastError << "'.";
		throw ::std::logic_error(errMsg.str());
	}

	Win32Window mainWindow(&WndProc, appTitle, hMenu);

	return mainWindow.Join(hAccelTable);
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) {
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId) {
		case IDM_ABOUT:
			DialogBox(WinMainParameters::GetHInstance(), MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		{
			RECT clientRect;
			GetClientRect(hWnd, &clientRect);
			// HGDIOBJ objects obtained from GetStockObject do not need to be deleted with DeleteObject as per the documentation: https://msdn.microsoft.com/en-us/library/dd144925(v=vs.85).aspx
			HGDIOBJ whiteBrushGDIObj = GetStockObject(WHITE_BRUSH);
			if (whiteBrushGDIObj == nullptr || GetObjectType(whiteBrushGDIObj) != OBJ_BRUSH) {
				PostQuitMessage(1);
			}
			else {
				HBRUSH whiteBrush = static_cast<HBRUSH>(whiteBrushGDIObj);
				FillRect(hdc, &clientRect, whiteBrush);
				COLORREF blackTextColor = 0x00000000;
				if (SetTextColor(hdc, blackTextColor) == CLR_INVALID) {
					PostQuitMessage(1);
				}
				else {
					const wchar_t helloWorldString[] = L"Hello world!";
					DrawTextW(hdc, helloWorldString, ARRAYSIZE(helloWorldString), &clientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
				}
			}
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (message) {
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
