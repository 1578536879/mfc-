// Insert.cpp : 实现文件
//

#include "stdafx.h"
#include "YX_TEST3_2.h"
#include "Insert.h"
#include "afxdialogex.h"


// CInsert 对话框

IMPLEMENT_DYNAMIC(CInsert, CDialogEx)

CInsert::CInsert(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInsert::IDD, pParent)
{

}

CInsert::~CInsert()
{
}

void CInsert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INSERT_SEX, m_sex);
}


BEGIN_MESSAGE_MAP(CInsert, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInsert::OnBnClickedOk)
END_MESSAGE_MAP()


// CInsert 消息处理程序


void CInsert::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	srand(time(NULL));
	int photo = rand()%20;
	m_info.Format("%d",photo);
	m_info += " ";
	CString str;
	GetDlgItemText(IDC_CLASS, str);
	if(str == ""){
		AfxMessageBox("请输入班级");
		return ;
	}
	m_info += str;
	m_info += " ";
	GetDlgItemText(IDC_INSERT_NAME, str);
	if(str == ""){
		AfxMessageBox("请输入姓名");
		return ;
	}
	m_info += str;
	m_info += " ";
	GetDlgItemText(IDC_INSERT_ID, str);
	if(str == ""){
		AfxMessageBox("请输入身份证号");
		return ;
	}
	m_info += str;
	m_info += " ";
	int xx = m_sex.GetCurSel();
	if(xx == 0){
		m_info += "0 ";
	}else {
		m_info += "1 ";
	}
	GetDlgItemText(IDC_DATETIMEPICKER1, str);
	if(str == ""){
		AfxMessageBox("请输入出生日期");
		return ;
	}
	m_info += str;
	m_info += " ";
	GetDlgItemText(IDC_INSERT_OTHER, str);
	if(str == ""){
		str = "NULL";
	}
	m_info += str;
	m_info += " ";

	CDialogEx::OnOK();
}


BOOL CInsert::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_sex.AddString("男");
	m_sex.AddString("女");
	return TRUE;  // return TRUE unless you set the focus to a control

	// 异常: OCX 属性页应返回 FALSE
}
