#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include <time.h>
#include <stdlib.h>


// CInsert �Ի���

class CInsert : public CDialogEx
{
	DECLARE_DYNAMIC(CInsert)

public:
	CInsert(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsert();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_sex;
	CString m_info;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
