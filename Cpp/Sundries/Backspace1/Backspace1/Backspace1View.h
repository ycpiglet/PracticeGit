
// Backspace1View.h : CBackspace1View Ŭ������ �������̽�
//

#pragma once


class CBackspace1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CBackspace1View();
	DECLARE_DYNCREATE(CBackspace1View)

// Ư���Դϴ�.
public:
	CBackspace1Doc* GetDocument() const;
	CString m_str;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CBackspace1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // Backspace1View.cpp�� ����� ����
inline CBackspace1Doc* CBackspace1View::GetDocument() const
   { return reinterpret_cast<CBackspace1Doc*>(m_pDocument); }
#endif

