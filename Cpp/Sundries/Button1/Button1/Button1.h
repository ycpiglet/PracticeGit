
// Button1.h : Button1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CButton1App:
// �� Ŭ������ ������ ���ؼ��� Button1.cpp�� �����Ͻʽÿ�.
//

class CButton1App : public CWinAppEx
{
public:
	CButton1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CButton1App theApp;
