// Info.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "YX_TEST3_2.h"
#include "Info.h"
#include "Insert.h"


// CInfo

IMPLEMENT_DYNCREATE(CInfo, CFormView)

CInfo::CInfo()
	: CFormView(CInfo::IDD)
{

}

CInfo::~CInfo()
{
}


void CInfo::init()
{
	int nWidth=GetSystemMetrics(SM_CXSCREEN);  //��Ļ���    
	int nHeight=GetSystemMetrics(SM_CYSCREEN); //��Ļ�߶�
	m_listCtrl = new CListCtrl;
	m_listCtrl->Create(WS_VISIBLE|WS_BORDER|LVS_EX_GRIDLINES, CRect(0, nHeight - 500, nWidth, nHeight), this, ID_INFO_LIST);
	m_listCtrl->ShowWindow(SW_SHOWNORMAL);
	m_listCtrl->ModifyStyle(0, LVS_OWNERDATA|LVS_REPORT);
	m_listCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_listCtrl->InsertColumn(0, _T("�༶"), LVCFMT_CENTER, 100, 0);
	m_listCtrl->InsertColumn(1, _T("����"), LVCFMT_CENTER, 100, 1);
	m_listCtrl->InsertColumn(2, _T("���֤��"), LVCFMT_CENTER, 150, 2);
	m_listCtrl->InsertColumn(3, _T("�Ա�"), LVCFMT_CENTER, 50, 4);
	m_listCtrl->InsertColumn(4, _T("��������"), LVCFMT_CENTER, 150, 3);
	m_listCtrl->InsertColumn(5, _T("��ע"), LVCFMT_CENTER, 150, 5);
	
	CYX_TEST3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	memcpy(m_bitmap, pDoc->m_bitmap, sizeof(pDoc->m_bitmap));
	m_info = pDoc->getInfo();
	m_name = new CEdit();
	m_name->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,CRect(330, 50, 480, 70),this, ID_INFO_NAME);
	
	m_class = new CEdit();
	m_class->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,CRect(330, 80, 480, 100),this, ID_INFO_CLASS);
	
	m_id = new CEdit();
	m_id->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,CRect(330, 110, 480, 130),this, ID_INFO_ID);
	
	m_sex = new CComboBox();
	m_sex->Create(WS_CHILD | WS_VISIBLE| CBS_DROPDOWN | CBS_HASSTRINGS | WS_VSCROLL, CRect(330, 140, 480, 200), this, ID_INFO_SEX);
	m_sex->AddString("��");
	m_sex->AddString("Ů");

	m_date = new CEdit();
	m_date->Create(WS_CHILD | WS_VISIBLE| CBS_DROPDOWN | CBS_HASSTRINGS | WS_VSCROLL, CRect(330, 170, 480, 190), this, ID_INFO_DATE);

	m_other = new CEdit();
	m_other->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,CRect(330, 200, 480, 220),this, ID_INFO_OTHER);
	
	m_index = 0;
	
	m_insert = new CButton;
	m_modify = new CButton;
	m_delete = new CButton;
	m_insert->Create(_T("����"),WS_CHILD ,CRect(600,80, 650, 100),this,ID_INFO_INSERT);
	m_insert->ShowWindow(SW_SHOWNORMAL);
	m_modify->Create(_T("�޸�"),WS_CHILD ,CRect(600,140, 650, 160),this,ID_INFO_MODIFY);
	m_modify->ShowWindow(SW_SHOWNORMAL);
	m_delete->Create(_T("ɾ��"),WS_CHILD ,CRect(600,210, 650, 230),this,ID_INFO_DELETE);
	m_delete->ShowWindow(SW_SHOWNORMAL);
}

void CInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CInfo, CFormView)
//	ON_COMMAND(ID_INFO_LIST, &CInfo::OnInfoList)
	ON_NOTIFY(NM_DBLCLK, ID_INFO_LIST, &CInfo::OnDblclkList)
	ON_COMMAND(ID_INFO_INSERT, &CInfo::OnInfoInsert)
	ON_COMMAND(ID_INFO_DELETE, &CInfo::OnInfoDelete)
	ON_COMMAND(ID_INFO_MODIFY, &CInfo::OnInfoModify)
//	ON_COMMAND(ID_INFO_LIST, &CInfo::OnInfoList)
END_MESSAGE_MAP()


// CInfo ���

#ifdef _DEBUG
void CInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
CYX_TEST3_2Doc* CInfo::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYX_TEST3_2Doc)));
	return (CYX_TEST3_2Doc*)m_pDocument;
}

#endif
#endif //_DEBUG


// CInfo ��Ϣ�������


void CInfo::OnDraw(CDC* pdc)
{
	// TODO: �ڴ����ר�ô����/����û���
	CYX_TEST3_2Doc *pdoc = GetDocument();
	CFont font;
	font.CreateFont(
		20, 10,0,0,80,
		FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,_T("����"));
	pdc->TextOut(250 ,50, _T("����"));
	pdc->TextOut(250 ,90, _T("�༶"));
	pdc->TextOut(250 ,120, _T("���֤��"));
	pdc->TextOut(250 ,150, _T("�Ա�"));
	pdc->TextOut(250 ,180, _T("��������"));
	pdc->TextOut(250 ,210, _T("��ע"));


	setInfo(m_index, pdc);
	setList();
}

void CInfo::OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult){
	int sel;
	sel = m_listCtrl->GetNextItem(-1, LVIS_SELECTED);
	if (sel < 0)
	{
		return;
	}
	m_index = sel;
	CDC *pdc = GetDC();
	setInfo(m_index, pdc);
}



void CInfo::setInfo(int index, CDC *pdc)
{
	if(m_info.size()==0){
		return ;
	}

	CYX_TEST3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CString str = m_info[index];
	int j = 0, i = 0, len;

	CString photo;
	i = str.Find(" ", j);
	len = i - j;
	photo = str.Mid(j, len);
	j+=(len + 1);
	int xx = _ttoi(photo);
	BITMAP bmp;
	m_bitmap[xx].GetBitmap(&bmp);
	CDC dcBit;
	dcBit.CreateCompatibleDC(pdc);
	CBitmap *poldmap = dcBit.SelectObject(&m_bitmap[xx]);
	CRect rect;
	SetRect(rect, 0,0,pDoc->getW(),pDoc->getH());
	pdc->StretchBlt(80, 80, rect.Width(), rect.Height(), &dcBit, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

	CString data;
	i = str.Find(" ", j);
	len = i - j;
	data = str.Mid(j, len);
	j+=(len + 1);
	m_class->SetWindowTextA(data);

	i = str.Find(" ", j);
	len = i - j;
	data = str.Mid(j, len);
	j+=(len + 1);
	m_name->SetWindowTextA(data);
	
	i = str.Find(" ", j);
	len = i - j;
	data = str.Mid(j, len);
	j+=(len + 1);
	m_id->SetWindowTextA(data);
	
	i = str.Find(" ", j);
	len = i - j;
	data = str.Mid(j, len);
	j+=(len + 1);
	xx = _ttoi(data);
	m_sex->SetCurSel(xx);

	
	i = str.Find(" ", j);
	len = i - j;
	data = str.Mid(j, len);
	j+=(len + 1);
	m_date->SetWindowTextA(data);

	
	i = str.Find(" ", j);
	len = i - j;
	data = str.Mid(j, len);
	j+=(len + 1);
	m_other->SetWindowTextA(data);
}


void CInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	init();
}


/*
	listctrl��������
*/
void CInfo::setList(){
	//ɾ��֮ǰ����Ԫ��
	m_listCtrl->DeleteAllItems();
	CString str, data;
	int index = 0, k = 0, len;
	for(int i=0;i<m_info.size();i++){
		k = 0;
		str = m_info[i];//����һ�е����ݣ�ÿ������������֮�����ɿո������
		//��һ��������ͼƬ���ݣ���������
		index = str.Find(" " ,k);//���ҵ�һ���ո�ĵط�
		len = index - k;//��ȡ���ݳ���
		k += (len + 1);//�Ƶ���һ�����ݿ�ͷ
		//�ڶ��������ǰ༶���ݣ��ڵ�һ�У������Ҫ��������
		index = str.Find(" " ,k);
		len = index - k;
		data = str.Mid(k, len);//���±�Ϊk����ȡ����Ϊlen������
		k += (len + 1);
		m_listCtrl->InsertItem(i, data);//�����һ������
		for(int j=1;j<6;j++){
			index = str.Find(" " ,k);
			len = index - k;
			data = str.Mid(k, len);
			if(j == 3){//�Ա�����01��ʾ�ģ������Ҫת��һ��
				if(data == "0"){//�������Ϊ0����ʾ�Ա�Ϊ��
					m_listCtrl->SetItemText(i, j,"��");
				}else if(data == "1"){//�������Ϊ1����ʾ�Ա�ΪŮ
					m_listCtrl->SetItemText(i, j,"Ů");
				}
			}else{//�����i�е�j�е�����
				if(!m_listCtrl->SetItemText(i, j,data)){
					AfxMessageBox("���ݸ���ʧ��~");//�������ʧ�ܣ���ô����ʾ����
				}
			}
			k += (len + 1);//�Ƶ���һ�����ݿ�ͷ
		}
	}
}

void CInfo::OnInfoInsert()
{
	// TODO: �ڴ���������������
	CInsert insert;
	insert.DoModal();
	CString str = insert.m_info;
	m_info.push_back(str);
	CYX_TEST3_2Doc *doc = GetDocument();
	doc->modifyInfo(m_info);
	setList();
}


void CInfo::OnInfoDelete()
{
	// TODO: �ڴ���������������
	int result = MessageBox( TEXT("�Ƿ�ɾ������Ϣ��") , TEXT("��ʾ") ,MB_YESNO);
	switch(result)
	{
	  case IDYES:
		{
			//���YES��ť�ľ���ʵ�ֹ���
			CDC *pdc = GetDC();
			m_info.erase(m_info.begin()+m_index);
			CYX_TEST3_2Doc *doc = GetDocument();
			doc->modifyInfo(m_info);
			if(m_index > m_info.size()){
				m_index = m_info.size() - 1;
			}
			setInfo(m_index,pdc);
			setList();
		}
	 case IDNO:
		break;
	}
}


void CInfo::OnInfoModify()
{
	// TODO: �ڴ���������������
	CString str;
	CString info;
	CString cst;
	cst = m_info[m_index];
	int index = cst.Find(" " ,0);
	int len = index;
	info = cst.Mid(0, len);
	info += " ";
	GetDlgItemText(ID_INFO_CLASS, str);
	if(str == ""){
		AfxMessageBox("������༶");
		return ;
	}
	info += str;
	info += " ";
	GetDlgItemText(ID_INFO_NAME, str);
	if(str == ""){
		AfxMessageBox("����������");
		return ;
	}
	info += str;
	info += " ";
	GetDlgItemText(ID_INFO_ID, str);
	if(str == ""){
		AfxMessageBox("���������֤��");
		return ;
	}
	info += str;
	info += " ";
	int xx = m_sex->GetCurSel();
	if(xx == 0){
		info += "0 ";
	}else {
		info += "1 ";
	}
	GetDlgItemText(ID_INFO_DATE, str);
	if(str == ""){
		AfxMessageBox("�������������");
		return ;
	}
	info += str;
	info += " ";
	GetDlgItemText(ID_INFO_OTHER, str);
	if(str == ""){
		str = "NULL";
	}
	info += str;
	info += " ";

	m_info[m_index] = info;
	
	CYX_TEST3_2Doc *doc = GetDocument();
	doc->modifyInfo(m_info);
	setList();
}


//void CInfo::OnInfoList()
//{
//	// TODO: �ڴ���������������
//
//}
