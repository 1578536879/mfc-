
// YX_TEST3_2.h : YX_TEST3_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CYX_TEST3_2App:
// �йش����ʵ�֣������ YX_TEST3_2.cpp
//

class CYX_TEST3_2App : public CWinAppEx
{
public:
	CYX_TEST3_2App();
	CMultiDocTemplate *m_template;
	CMultiDocTemplate* m_photoTemp;
	CMultiDocTemplate* m_infoTemp;
// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CYX_TEST3_2App theApp;
