// PhotoChildFrm.cpp : 实现文件
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


// CPhotoChildFrm 消息处理程序


BOOL CPhotoChildFrm::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
	lpcs->x=400;
	lpcs->y=400;
	return CMDIChildWnd::OnCreateClient(lpcs, pContext);
}


BOOL CPhotoChildFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	cs.cx = 400;
    cs.cy = 400;
	cs.x = 400;
	cs.y = 50;
	return CMDIChildWnd::PreCreateWindow(cs);
}
