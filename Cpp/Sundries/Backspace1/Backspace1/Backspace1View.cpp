
// Backspace1View.cpp : CBackspace1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Backspace1.h"
#endif

#include "Backspace1Doc.h"
#include "Backspace1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBackspace1View

IMPLEMENT_DYNCREATE(CBackspace1View, CView)

BEGIN_MESSAGE_MAP(CBackspace1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CBackspace1View 생성/소멸

CBackspace1View::CBackspace1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CBackspace1View::~CBackspace1View()
{
}

BOOL CBackspace1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBackspace1View 그리기

void CBackspace1View::OnDraw(CDC* pDC)
{
	CBackspace1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_str, &rect, DT_LEFT);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CBackspace1View 인쇄

BOOL CBackspace1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CBackspace1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CBackspace1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CBackspace1View 진단

#ifdef _DEBUG
void CBackspace1View::AssertValid() const
{
	CView::AssertValid();
}

void CBackspace1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBackspace1Doc* CBackspace1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBackspace1Doc)));
	return (CBackspace1Doc*)m_pDocument;
}
#endif //_DEBUG


// CBackspace1View 메시지 처리기


void CBackspace1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar >= 32) { // 제어 문자를 제외시킨다.
		m_str.AppendChar(nChar);
		Invalidate();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CBackspace1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	switch (nChar)
	{
		case VK_RETURN: // 엔터가 눌리면

			m_str.AppendChar(nChar); // 정상적으로 나온다
			Invalidate();

			break;

		case VK_BACK: // 백스페이스가 눌리면

			if (m_str.GetLength() > 0)
			{
				m_str.Delete(m_str.GetLength() - 1, 1); // 하나씩 지운다
				Invalidate();
			}

			break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
