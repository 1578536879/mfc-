#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include <time.h>
#include <stdlib.h>


// CInsert 对话框

class CInsert : public CDialogEx
{
	DECLARE_DYNAMIC(CInsert)

public:
	CInsert(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInsert();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_sex;
	CString m_info;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
