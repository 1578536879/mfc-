// InfoChildFrm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "YX_TEST3_2.h"
#include "InfoChildFrm.h"


// CInfoChildFrm

IMPLEMENT_DYNCREATE(CInfoChildFrm, CMDIChildWnd)

CInfoChildFrm::CInfoChildFrm()
{

}

CInfoChildFrm::~CInfoChildFrm()
{
}


BEGIN_MESSAGE_MAP(CInfoChildFrm, CMDIChildWnd)
END_MESSAGE_MAP()


// CInfoChildFrm ��Ϣ�������


BOOL CInfoChildFrm::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
	lpcs->x=400;
	lpcs->y=400;
	return CMDIChildWnd::OnCreateClient(lpcs, pContext);
}


BOOL CInfoChildFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���
	cs.cx = 800;
    cs.cy = 500;
	return CMDIChildWnd::PreCreateWindow(cs);
}
