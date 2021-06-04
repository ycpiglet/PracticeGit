
// Backspace1View.h : CBackspace1View 클래스의 인터페이스
//

#pragma once


class CBackspace1View : public CView
{
protected: // serialization에서만 만들어집니다.
	CBackspace1View();
	DECLARE_DYNCREATE(CBackspace1View)

// 특성입니다.
public:
	CBackspace1Doc* GetDocument() const;
	CString m_str;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CBackspace1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // Backspace1View.cpp의 디버그 버전
inline CBackspace1Doc* CBackspace1View::GetDocument() const
   { return reinterpret_cast<CBackspace1Doc*>(m_pDocument); }
#endif

