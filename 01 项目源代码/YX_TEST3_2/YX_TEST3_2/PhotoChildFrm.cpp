// PhotoChildFrm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "YX_TEST3_2.h"
#include "PhotoChildFrm.h"


// CPhotoChildFrm

IMPLEMENT_DYNCREATE(CPhotoChildFrm, CMDIChildWnd)

CPhotoChildFrm::CPhotoChildFrm()
{

}

CPhotoChildFrm::~CPhotoChildFrm()
{
}


BEGIN_MESSAGE_MAP(CPhotoChildFrm, CMDIChildWnd)
END_MESSAGE_MAP()


// CPhotoChildFrm ��Ϣ�������


BOOL CPhotoChildFrm::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
	lpcs->x=400;
	lpcs->y=400;
	return CMDIChildWnd::OnCreateClient(lpcs, pContext);
}


BOOL CPhotoChildFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���
	cs.cx = 400;
    cs.cy = 400;
	cs.x = 400;
	cs.y = 50;
	return CMDIChildWnd::PreCreateWindow(cs);
}
