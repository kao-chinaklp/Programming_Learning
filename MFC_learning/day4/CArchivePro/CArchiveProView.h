
// CArchiveProView.h: CCArchiveProView 类的接口
//

#pragma once


class CCArchiveProView : public CView
{
protected: // 仅从序列化创建
	CCArchiveProView() noexcept;
	DECLARE_DYNCREATE(CCArchiveProView)

// 特性
public:
	CCArchiveProDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCArchiveProView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // CArchiveProView.cpp 中的调试版本
inline CCArchiveProDoc* CCArchiveProView::GetDocument() const
   { return reinterpret_cast<CCArchiveProDoc*>(m_pDocument); }
#endif

