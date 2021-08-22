
// DocViewView.h: CDocViewView 类的接口
//

#pragma once


class CDocViewView : public CFormView
{
protected: // 仅从序列化创建
	CDocViewView() noexcept;
	DECLARE_DYNCREATE(CDocViewView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DOCVIEW_FORM };
#endif

// 特性
public:
	CDocViewDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDocViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	CButton m_ButtomPre;
private:
	CButton m_ButtomNext;
	CButton m_ButtomPre;
	int mui_Id;
	CString mui_Name;
	int mui_Age;
	int mui_Score;
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // DocViewView.cpp 中的调试版本
inline CDocViewDoc* CDocViewView::GetDocument() const
   { return reinterpret_cast<CDocViewDoc*>(m_pDocument); }
#endif

