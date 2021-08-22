
// PartsDlg.h: 头文件
//

#pragma once

#include "MyButtom.h"

// CPartsDlg 对话框
class CPartsDlg : public CDialogEx
{
// 构造
public:
	CPartsDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PARTS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	MyButtom m_Buttom;
	CString m_str;
public:
	afx_msg void OnBnClickedButton4();
private:
	CEdit m_e1;
	CEdit m_e2;
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
