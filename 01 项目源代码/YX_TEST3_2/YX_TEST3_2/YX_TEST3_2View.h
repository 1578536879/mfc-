
// YX_TEST3_2View.h : CYX_TEST3_2View ��Ľӿ�
//

#pragma once


class CYX_TEST3_2View : public CView
{
protected: // �������л�����
	CYX_TEST3_2View();
	DECLARE_DYNCREATE(CYX_TEST3_2View)

// ����
public:
	CYX_TEST3_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CYX_TEST3_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // YX_TEST3_2View.cpp �еĵ��԰汾
inline CYX_TEST3_2Doc* CYX_TEST3_2View::GetDocument() const
   { return reinterpret_cast<CYX_TEST3_2Doc*>(m_pDocument); }
#endif

