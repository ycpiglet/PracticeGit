
// Button1View.h : CButton1View Ŭ������ �������̽�
//

#pragma once


class CButton1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CButton1View();
	DECLARE_DYNCREATE(CButton1View)

// Ư���Դϴ�.
public:
	CButton1Doc* GetDocument() const;

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
	virtual ~CButton1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Button1View.cpp�� ����� ����
inline CButton1Doc* CButton1View::GetDocument() const
   { return reinterpret_cast<CButton1Doc*>(m_pDocument); }
#endif

