
// Backspace1.h : Backspace1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CBackspace1App:
// �� Ŭ������ ������ ���ؼ��� Backspace1.cpp�� �����Ͻʽÿ�.
//

class CBackspace1App : public CWinAppEx
{
public:
	CBackspace1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBackspace1App theApp;
