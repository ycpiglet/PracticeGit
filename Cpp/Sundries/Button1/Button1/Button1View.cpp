
// Button1View.cpp : CButton1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Button1.h"
#endif

#include "Button1Doc.h"
#include "Button1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButton1View

IMPLEMENT_DYNCREATE(CButton1View, CView)

BEGIN_MESSAGE_MAP(CButton1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CButton1View ����/�Ҹ�

CButton1View::CButton1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CButton1View::~CButton1View()
{
}

BOOL CButton1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CButton1View �׸���

void CButton1View::OnDraw(CDC* /*pDC*/)
{
	CButton1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CButton1View �μ�

BOOL CButton1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CButton1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CButton1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CButton1View ����

#ifdef _DEBUG
void CButton1View::AssertValid() const
{
	CView::AssertValid();
}

void CButton1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButton1Doc* CButton1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButton1Doc)));
	return (CButton1Doc*)m_pDocument;
}
#endif //_DEBUG


// CButton1View �޽��� ó����
