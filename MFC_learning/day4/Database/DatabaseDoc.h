
// DatabaseDoc.h: CDatabaseDoc 类的接口
//


#pragma once
#include "DatabaseSet.h"


class CDatabaseDoc : public CDocument
{
protected: // 仅从序列化创建
	CDatabaseDoc() noexcept;
	DECLARE_DYNCREATE(CDatabaseDoc)
private:
	CDatabaseSet m_pMySet;
// 特性
public:
	int m_id;
	CString m_name;
	int m_age;
	int m_score;

// 操作
public:
	CDatabaseSet* GetMySet()
	{
		return &m_pMySet;
	}

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
	virtual ~CDatabaseDoc();
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
};
