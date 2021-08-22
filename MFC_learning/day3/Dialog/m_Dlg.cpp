// m_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "Dialog.h"
#include "m_Dlg.h"
#include "afxdialogex.h"


// m_Dlg 对话框

IMPLEMENT_DYNAMIC(m_Dlg, CDialogEx)

m_Dlg::m_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

m_Dlg::~m_Dlg()
{
}

void m_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(m_Dlg, CDialogEx)
END_MESSAGE_MAP()


// m_Dlg 消息处理程序
