#pragma once


// CInfoChildFrm ���

class CInfoChildFrm : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CInfoChildFrm)
protected:
	CInfoChildFrm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CInfoChildFrm();

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


