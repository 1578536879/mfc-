#pragma once


// CInfoChildFrm 框架

class CInfoChildFrm : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CInfoChildFrm)
protected:
	CInfoChildFrm();           // 动态创建所使用的受保护的构造函数
	virtual ~CInfoChildFrm();

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


