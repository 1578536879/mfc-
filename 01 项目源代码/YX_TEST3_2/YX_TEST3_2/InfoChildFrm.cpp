// InfoChildFrm.cpp : 实现文件
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


// CInfoChildFrm 消息处理程序


BOOL CInfoChildFrm::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
	lpcs->x=400;
	lpcs->y=400;
	return CMDIChildWnd::OnCreateClient(lpcs, pContext);
}


BOOL CInfoChildFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	cs.cx = 800;
    cs.cy = 500;
	return CMDIChildWnd::PreCreateWindow(cs);
}
