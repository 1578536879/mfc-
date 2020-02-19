#pragma once

#include "YX_TEST3_2Doc.h"
#include <vector>
#include<cstring>
using namespace std;


// CInfo 窗体视图

class CInfo : public CFormView
{
	DECLARE_DYNCREATE(CInfo)
	vector<CString> m_info;
	CListCtrl *m_listCtrl;
	CEdit* m_name;
	CEdit *m_class;
	CEdit *m_id;
	CEdit *m_other;
	CComboBox *m_sex;
	CEdit *m_date;
	CBitmap m_bitmap[20];
	CButton *m_insert;
	CButton *m_modify;
	CButton *m_delete;
	int m_index;
	
protected:
	CInfo();           // 动态创建所使用的受保护的构造函数
	virtual ~CInfo();

public:
	enum { IDD = IDD_INFO };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
//	afx_msg void OnInfoList();
	afx_msg void OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	CYX_TEST3_2Doc* GetDocument() const;
	void setInfo(int index, CDC *pdc);
	void setList();
	void init();
	virtual void OnInitialUpdate();
	afx_msg void OnInfoInsert();
	afx_msg void OnInfoDelete();
	afx_msg void OnInfoModify();
//	afx_msg void OnInfoList();
};


