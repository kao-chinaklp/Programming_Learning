#include "mfc.h"

//����ֻ��һ��ȫ�ֵ�Ӧ�ó��������
MyApp myApp;

// �������ڵ�ַ
BOOL MyApp::InitInstance()
{
	/*
	* 1��������������
	* 2����ʾ����
	* 3�����´���
	* 4�������������ָ��
	*/

	// 1��������ܶ���
	MyFrame* frame = new MyFrame; //���캯��

	// 2����ʾ����
	frame->ShowWindow(SW_NORMAL);

	// 3�����´���
	frame->UpdateWindow();

	// 4������ָ��
	m_pMainWnd = frame;

	return TRUE;
}

// ������Ϣ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_WM_LBUTTONDOWN() // ��Ϣӳ����ڱ�־
	ON_WM_PAINT()
END_MESSAGE_MAP()

MyFrame::MyFrame()
{
	// CWnd ��ĳ�Ա����
	// CreateWnd �̳��� CWnd

	Create(NULL, TEXT("MFC"));
}

void MyFrame::OnLButtonDown(UINT, CPoint)
{
	//CWnd::MessageBox
	MessageBox(TEXT("������"));
}

void MyFrame::OnPaint()
{
	CPaintDC cdc(this);
	cdc.TextOutW(100, 100, TEXT("��ã�mfc"));
}