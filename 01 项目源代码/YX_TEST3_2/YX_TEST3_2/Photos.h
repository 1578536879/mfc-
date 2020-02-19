#pragma once
#include "YX_TEST3_2Doc.h"
#include <vector>
using namespace std;


// CPhotos 视图

class CPhotos : public CScrollView
{
	DECLARE_DYNCREATE(CPhotos)

	int m_startX;
	int m_startY;
	int m_w;
	int m_h;
	int m_intervalX;
	int m_intervalY;
	CBitmap m_bitmap[20];
protected:
	CPhotos();           // 动态创建所使用的受保护的构造函数
	virtual ~CPhotos();

public:
	CYX_TEST3_2Doc* GetDocument() const;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected: 
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
	virtual void OnInitialUpdate();     // 构造后的第一次

	DECLARE_MESSAGE_MAP()
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

};


