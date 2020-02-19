
// YX_TEST3_2Doc.h : CYX_TEST3_2Doc ��Ľӿ�
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
protected: // �������л�����
	CYX_TEST3_2Doc();
	DECLARE_DYNCREATE(CYX_TEST3_2Doc)

// ����
public:
	CBitmap m_bitmap[20];

// ����
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
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CYX_TEST3_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
};
