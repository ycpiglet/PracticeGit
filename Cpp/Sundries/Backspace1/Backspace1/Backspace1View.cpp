
// Backspace1View.cpp : CBackspace1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CBackspace1View ����/�Ҹ�

CBackspace1View::CBackspace1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CBackspace1View::~CBackspace1View()
{
}

BOOL CBackspace1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CBackspace1View �׸���

void CBackspace1View::OnDraw(CDC* pDC)
{
	CBackspace1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_str, &rect, DT_LEFT);
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CBackspace1View �μ�

BOOL CBackspace1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CBackspace1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CBackspace1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CBackspace1View ����

#ifdef _DEBUG
void CBackspace1View::AssertValid() const
{
	CView::AssertValid();
}

void CBackspace1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBackspace1Doc* CBackspace1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBackspace1Doc)));
	return (CBackspace1Doc*)m_pDocument;
}
#endif //_DEBUG


// CBackspace1View �޽��� ó����


void CBackspace1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar >= 32) { // ���� ���ڸ� ���ܽ�Ų��.
		m_str.AppendChar(nChar);
		Invalidate();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CBackspace1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	switch (nChar)
	{
		case VK_RETURN: // ���Ͱ� ������

			m_str.AppendChar(nChar); // ���������� ���´�
			Invalidate();

			break;

		case VK_BACK: // �齺���̽��� ������

			if (m_str.GetLength() > 0)
			{
				m_str.Delete(m_str.GetLength() - 1, 1); // �ϳ��� �����
				Invalidate();
			}

			break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
