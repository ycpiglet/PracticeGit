// CppCLR_WinformsProjekt.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;

//int main(array<System::String ^> ^args)
//{
//    Console::WriteLine(L"Hello World");
//    return 0;
//}


[STAThread]
int main() 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLR_WinformsProjekt::Form1()); // "CppCLR_WinformsProjekt" noch anpassen
	return 0;
}