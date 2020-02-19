
// YX_TEST3_2View.h : CYX_TEST3_2View 类的接口
//

#pragma once


class CYX_TEST3_2View : public CView
{
protected: // 仅从序列化创建
	CYX_TEST3_2View();
	DECLARE_DYNCREATE(CYX_TEST3_2View)

// 特性
public:
	CYX_TEST3_2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CYX_TEST3_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // YX_TEST3_2View.cpp 中的调试版本
inline CYX_TEST3_2Doc* CYX_TEST3_2View::GetDocument() const
   { return reinterpret_cast<CYX_TEST3_2Doc*>(m_pDocument); }
#endif

