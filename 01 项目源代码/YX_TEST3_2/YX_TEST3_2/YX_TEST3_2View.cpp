
// YX_TEST3_2View.cpp : CYX_TEST3_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "YX_TEST3_2.h"
#endif

#include "YX_TEST3_2Doc.h"
#include "YX_TEST3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYX_TEST3_2View

IMPLEMENT_DYNCREATE(CYX_TEST3_2View, CView)

BEGIN_MESSAGE_MAP(CYX_TEST3_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CYX_TEST3_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CYX_TEST3_2View ����/����

CYX_TEST3_2View::CYX_TEST3_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CYX_TEST3_2View::~CYX_TEST3_2View()
{
}

BOOL CYX_TEST3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CYX_TEST3_2View ����

void CYX_TEST3_2View::OnDraw(CDC* /*pDC*/)
{
	CYX_TEST3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CYX_TEST3_2View ��ӡ


void CYX_TEST3_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CYX_TEST3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CYX_TEST3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CYX_TEST3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CYX_TEST3_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CYX_TEST3_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CYX_TEST3_2View ���

#ifdef _DEBUG
void CYX_TEST3_2View::AssertValid() const
{
	CView::AssertValid();
}

void CYX_TEST3_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYX_TEST3_2Doc* CYX_TEST3_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYX_TEST3_2Doc)));
	return (CYX_TEST3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CYX_TEST3_2View ��Ϣ�������
