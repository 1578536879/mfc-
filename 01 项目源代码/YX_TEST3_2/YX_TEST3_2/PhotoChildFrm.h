#pragma once


// CPhotoChildFrm ���

class CPhotoChildFrm : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CPhotoChildFrm)
protected:
	CPhotoChildFrm();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPhotoChildFrm();

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


