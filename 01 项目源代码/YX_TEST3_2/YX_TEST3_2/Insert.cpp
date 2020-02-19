// Insert.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "YX_TEST3_2.h"
#include "Insert.h"
#include "afxdialogex.h"


// CInsert �Ի���

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


// CInsert ��Ϣ�������


void CInsert::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	srand(time(NULL));
	int photo = rand()%20;
	m_info.Format("%d",photo);
	m_info += " ";
	CString str;
	GetDlgItemText(IDC_CLASS, str);
	if(str == ""){
		AfxMessageBox("������༶");
		return ;
	}
	m_info += str;
	m_info += " ";
	GetDlgItemText(IDC_INSERT_NAME, str);
	if(str == ""){
		AfxMessageBox("����������");
		return ;
	}
	m_info += str;
	m_info += " ";
	GetDlgItemText(IDC_INSERT_ID, str);
	if(str == ""){
		AfxMessageBox("���������֤��");
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
		AfxMessageBox("�������������");
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
	m_sex.AddString("��");
	m_sex.AddString("Ů");
	return TRUE;  // return TRUE unless you set the focus to a control

	// �쳣: OCX ����ҳӦ���� FALSE
}
