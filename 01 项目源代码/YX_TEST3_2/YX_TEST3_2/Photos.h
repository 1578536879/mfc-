#pragma once
#include "YX_TEST3_2Doc.h"
#include <vector>
using namespace std;


// CPhotos ��ͼ

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
	CPhotos();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
	virtual void OnInitialUpdate();     // �����ĵ�һ��

	DECLARE_MESSAGE_MAP()
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

};


