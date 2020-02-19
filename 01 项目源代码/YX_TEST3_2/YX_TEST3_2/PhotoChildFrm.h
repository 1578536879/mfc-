#pragma once


// CPhotoChildFrm 框架

class CPhotoChildFrm : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CPhotoChildFrm)
protected:
	CPhotoChildFrm();           // 动态创建所使用的受保护的构造函数
	virtual ~CPhotoChildFrm();

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


