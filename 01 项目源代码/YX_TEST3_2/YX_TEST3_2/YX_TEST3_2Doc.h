
// YX_TEST3_2Doc.h : CYX_TEST3_2Doc 类的接口
//


#pragma once
#include<vector>
#include <iterator>
#include <sstream>
using namespace std;


class CYX_TEST3_2Doc : public CDocument
{
	int m_startX;
	int m_startY;
	int m_w;
	int m_h;
	int m_intervalX;
	int m_intervalY;
	vector<CString> m_info;
protected: // 仅从序列化创建
	CYX_TEST3_2Doc();
	DECLARE_DYNCREATE(CYX_TEST3_2Doc)

// 特性
public:
	CBitmap m_bitmap[20];

// 操作
public:
	bool modifyInfo(vector<CString> info);
	vector<CString> getInfo();
	void getCBitmap();
	int getstartX();
	int getstartY();
	int getW();
	int getH();
	int getIntervalX();
	int getIntervalY();
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CYX_TEST3_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
};
