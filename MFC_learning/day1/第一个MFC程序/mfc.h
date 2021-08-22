#pragma once

#include <afxwin.h>

// 1)应用程序类 CWinApp
class MyApp :public CWinApp
{
public:
	// 基类的虚函数
	// 派生类只是重写
	// MFC的程序入口地址
	virtual BOOL InitInstance();

private:
};

// 2）框架类 CFrameWnd
class MyFrame :public CFrameWnd
{
public:
	MyFrame();

	//声明消息映射宏
	DECLARE_MESSAGE_MAP();

	afx_msg void OnLButtonDown(UINT, CPoint);

	afx_msg void OnPaint();

private:
};