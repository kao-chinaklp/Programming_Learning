#include "mfc.h"

//有且只有一个全局的应用程序类对象
MyApp myApp;

// 程序的入口地址
BOOL MyApp::InitInstance()
{
	/*
	* 1、创建框架类对象
	* 2、显示窗口
	* 3、更新窗口
	* 4、保存框架类对象指针
	*/

	// 1、创建框架对象
	MyFrame* frame = new MyFrame; //构造函数

	// 2、显示窗口
	frame->ShowWindow(SW_NORMAL);

	// 3、更新窗口
	frame->UpdateWindow();

	// 4、保存指针
	m_pMainWnd = frame;

	return TRUE;
}

// 定义消息宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN() // 消息映射入口标志
	ON_WM_PAINT()
END_MESSAGE_MAP()

MyFrame::MyFrame()
{
	// CWnd 类的成员函数
	// CreateWnd 继承于 CWnd

	Create(NULL, TEXT("MFC"));
}

void MyFrame::OnLButtonDown(UINT, CPoint)
{
	//CWnd::MessageBox
	MessageBox(TEXT("鼠标左键"));
}

void MyFrame::OnPaint()
{
	CPaintDC cdc(this);
	cdc.TextOutW(100, 100, TEXT("你好，mfc"));
}