// Photos.cpp : 实现文件
//

#include "stdafx.h"
#include "YX_TEST3_2.h"
#include "Photos.h"
#include "YX_TEST3_2Doc.h"
#include <cstring>

// CPhotos

IMPLEMENT_DYNCREATE(CPhotos, CScrollView)

CPhotos::CPhotos()
{
	
}

CPhotos::~CPhotos()
{
}


BEGIN_MESSAGE_MAP(CPhotos, CScrollView)
END_MESSAGE_MAP()


// CPhotos 绘图

void CPhotos::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	CClientDC dc(this);
	
	sizeTotal.cx = (7 * dc.GetDeviceCaps(LOGPIXELSX));
	sizeTotal.cy = (6 * dc.GetDeviceCaps(LOGPIXELSY));
	SetScrollSizes(MM_TEXT, sizeTotal);
	
	CYX_TEST3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	 memcpy(m_bitmap, pDoc->m_bitmap, sizeof(pDoc->m_bitmap));
	 m_w = pDoc->getW();
	 m_h = pDoc->getH();
	 m_intervalX = pDoc->getIntervalX();
	 m_intervalY = pDoc->getIntervalY();
}

void CPhotos::OnDraw(CDC* pDC)
{
	CYX_TEST3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_startX = pDoc->getstartX();
	m_startY = pDoc->getstartY();
	// TODO: 在此添加绘制代码
	for(int i=0;i<20;i++){
		BITMAP bmp;
		m_bitmap[i].GetBitmap(&bmp);
		CDC dcBit;
		dcBit.CreateCompatibleDC(pDC);
		CBitmap *poldmap = dcBit.SelectObject(&m_bitmap[i]);
		CRect rect;
		SetRect(rect, 0,0,m_w,m_h);

		pDC->StretchBlt(m_startX, m_startY, rect.Width(), rect.Height(), & dcBit, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

		m_startX += (m_w + m_intervalX);
		if((i+1)%5==0){
			m_startX = 10;
			m_startY += (m_h + m_intervalY);
		}
	}
	
}


// CPhotos 诊断

#ifdef _DEBUG
void CPhotos::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CPhotos::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
CYX_TEST3_2Doc* CPhotos::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYX_TEST3_2Doc)));
	return (CYX_TEST3_2Doc*)m_pDocument;
}

#endif
#endif //_DEBUG


// CPhotos 消息处理程序


void CPhotos::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 在此添加专用代码和/或调用基类

	CScrollView::OnPrint(pDC, pInfo);
}
