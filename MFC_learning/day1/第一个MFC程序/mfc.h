#pragma once

#include <afxwin.h>

// 1)Ӧ�ó����� CWinApp
class MyApp :public CWinApp
{
public:
	// ������麯��
	// ������ֻ����д
	// MFC�ĳ�����ڵ�ַ
	virtual BOOL InitInstance();

private:
};

// 2������� CFrameWnd
class MyFrame :public CFrameWnd
{
public:
	MyFrame();

	//������Ϣӳ���
	DECLARE_MESSAGE_MAP();

	afx_msg void OnLButtonDown(UINT, CPoint);

	afx_msg void OnPaint();

private:
};