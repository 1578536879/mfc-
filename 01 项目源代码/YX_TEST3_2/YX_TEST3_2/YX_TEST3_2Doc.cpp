
// YX_TEST3_2Doc.cpp : CYX_TEST3_2Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "YX_TEST3_2.h"
#endif

#include "YX_TEST3_2Doc.h"

#include <propkey.h>
#include <locale.h>
#include <iostream>  
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CYX_TEST3_2Doc

IMPLEMENT_DYNCREATE(CYX_TEST3_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CYX_TEST3_2Doc, CDocument)
END_MESSAGE_MAP()


// CYX_TEST3_2Doc 构造/析构

CYX_TEST3_2Doc::CYX_TEST3_2Doc()
{
	// TODO: 在此添加一次性构造代码
	getCBitmap();
	 m_startX = 10;
	 m_startY = 10;
	 m_w = 100;
	 m_h = 100;
	 m_intervalX = 20;
	 m_intervalY = 50;
}

CYX_TEST3_2Doc::~CYX_TEST3_2Doc()
{
}

BOOL CYX_TEST3_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CYX_TEST3_2Doc 序列化

void CYX_TEST3_2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CYX_TEST3_2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CYX_TEST3_2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CYX_TEST3_2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CYX_TEST3_2Doc 诊断

#ifdef _DEBUG
void CYX_TEST3_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CYX_TEST3_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CYX_TEST3_2Doc 命令


bool CYX_TEST3_2Doc::modifyInfo(vector<CString> info)
{
	fstream outfile("INFO.dat", ios::out | ios::trunc);
	//ofstream outfile("INFO.dat", ofstream::app);
	if(outfile.is_open()){
		std::stringstream ss;
		string infoStr;
		std::copy(info.begin(), info.end(), ostream_iterator<CString>(ss, ""));
		infoStr = ss.str();
		
		int index = 0, len, j = 0;
		CString str;
		for(j=0;j<infoStr.length();){
			string photo;
			index = infoStr.find(" ", j);
			len = index - j;
			photo = infoStr.substr(j, len);
			j+=(len + 1);

			string cla;
			index = infoStr.find(" ", j);
			len = index - j;
			cla = infoStr.substr(j, len);
			j+=(len + 1);

			string name;
			index = infoStr.find(" ", j);
			len = index - j;
			name = infoStr.substr(j, len);
			j+=(len + 1);
			
			string id;
			index = infoStr.find(" ", j);
			len = index - j;
			id = infoStr.substr(j, len);
			j+=(len + 1);
			
			string sex;
			index = infoStr.find(" ", j);
			len = index - j;
			sex = infoStr.substr(j, len);
			j+=(len + 1);
			
			string date;
			index = infoStr.find(" ", j);
			len = index - j;
			date = infoStr.substr(j, len);
			j+=(len + 1);
			
			string other;
			index = infoStr.find(" ", j);
			len = index - j;
			other = infoStr.substr(j, len);
			j+=(len + 1);

			string text =photo + " " + cla + " " + name + " " + id  + " " + sex  + " " + date  + " " + other;
			outfile << text<<" \n";
		}
		outfile.close();
		return true;
	}
	return false;
}

vector<CString> CYX_TEST3_2Doc::getInfo(){
	CString str;
	//由于txt文件中文字符会有编码问题，所以读取二进制文件
	ifstream infile("INFO.dat");
	string temp;
	//打开文件
	if(!infile.is_open()){
		return m_info;
	}else {
		//读取文件
		while (getline(infile, temp))
		{
			//将读取的数据存入数组
			str = temp.c_str();
			m_info.push_back(str);
		}
	}
	//关闭文件
	infile.close();
	return m_info;
}
void CYX_TEST3_2Doc::getCBitmap(){
	 m_bitmap[0].LoadBitmap(IDB_BITMAP1);
	 m_bitmap[1].LoadBitmap(IDB_BITMAP2);
	 m_bitmap[2].LoadBitmap(IDB_BITMAP3);
	 m_bitmap[3].LoadBitmap(IDB_BITMAP4);
	 m_bitmap[4].LoadBitmap(IDB_BITMAP5);
	 m_bitmap[5].LoadBitmap(IDB_BITMAP6);
	 m_bitmap[6].LoadBitmap(IDB_BITMAP7);
	 m_bitmap[7].LoadBitmap(IDB_BITMAP8);
	 m_bitmap[8].LoadBitmap(IDB_BITMAP9);
	 m_bitmap[9].LoadBitmap(IDB_BITMAP10);
	 m_bitmap[10].LoadBitmap(IDB_BITMAP11);
	 m_bitmap[11].LoadBitmap(IDB_BITMAP12);
	 m_bitmap[12].LoadBitmap(IDB_BITMAP13);
	 m_bitmap[13].LoadBitmap(IDB_BITMAP14);
	 m_bitmap[14].LoadBitmap(IDB_BITMAP15);
	 m_bitmap[15].LoadBitmap(IDB_BITMAP16);
	 m_bitmap[16].LoadBitmap(IDB_BITMAP17);
	 m_bitmap[17].LoadBitmap(IDB_BITMAP18);
	 m_bitmap[18].LoadBitmap(IDB_BITMAP19);
	 m_bitmap[19].LoadBitmap(IDB_BITMAP20);
}

int CYX_TEST3_2Doc::getstartX(){
	return m_startX;
}
int CYX_TEST3_2Doc::getstartY(){
	return m_startY;
}
int CYX_TEST3_2Doc::getW(){
	return m_w;
}
int CYX_TEST3_2Doc::getH(){
	return m_h;
}
int CYX_TEST3_2Doc::getIntervalX(){
	return m_intervalX;
}
int CYX_TEST3_2Doc::getIntervalY(){
	return m_intervalY;
}