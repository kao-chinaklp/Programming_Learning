
// ListBoxDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "ListBox.h"
#include "ListBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CListBoxDlg 对话框



CListBoxDlg::CListBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTBOX_DIALOG, pParent)
	, m_str(_T(""))
	, m_pos(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox);
	DDX_Text(pDX, IDC_EDIT2, m_pos);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_sB);
}

BEGIN_MESSAGE_MAP(CListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CListBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CListBoxDlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &CListBoxDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON3, &CListBoxDlg::OnBnClickedButton3)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CListBoxDlg 消息处理程序

BOOL CListBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString str;

	m_comboBox.SetCurSel(0);//设置默认显示项
	m_comboBox.GetLBText(0, str);
	//MessageBox(str);

	m_comboBox.AddString(TEXT("测试"));

	//添加内容

	m_pos = 50;

	UpdateData(FALSE);
	//设置滑块范围
	m_sB.SetScrollRange(1, 100);
	//设置位置
	m_sB.SetScrollPos(m_pos);
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CListBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//添加
void CListBoxDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取编辑区内容
	UpdateData(TRUE);

	if (m_str.GetLength() == 0)
	{
		MessageBox(TEXT("内容不能为空！"));
		return;
	}

	//给列表框添加内容
	m_listbox.AddString(m_str);

	m_str.Empty();

	//把内容更新到编辑区
	UpdateData(FALSE);
}

//删除
void CListBoxDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取当前选中的行
	int i = m_listbox.GetCurSel();

	//删除
	m_listbox.DeleteString(i);
}

//点击选中的内容自动触发
void CListBoxDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取选中内容
	//获取当前选中的行
	int i = m_listbox.GetCurSel();

	//获取指定位置内容
	m_listbox.GetText(i, m_str);

	//更新到编辑区
	UpdateData(FALSE);

}

//修改
void CListBoxDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//更新编辑区内容到m_str
	UpdateData(TRUE);

	if (m_str.GetLength() == 0)
	{
		MessageBox(TEXT("内容不能为空！"));
		return;
	}
	//获取选中行引索
	int i = m_listbox.GetCurSel();

	//删除指定行内容
	m_listbox.DeleteString(i);

	//指定位置插入内容
	m_listbox.InsertString(i, m_str);

	UpdateData(FALSE);
}

//滑块事件，只有操作滑块，nPos才有值
void CListBoxDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int tmpPos;

	if (pScrollBar == &m_sB)
	{
		switch (nSBCode)
		{
		case SB_THUMBPOSITION://滑块位置
		{
			m_sB.SetScrollPos(nPos);
			m_pos = nPos;
			UpdateData(FALSE);
			break;
		}
		case SB_LINELEFT://向左的箭头
		{
			//获取滑块位置
			tmpPos = m_sB.GetScrollPos() - 1;
			if (tmpPos < 0)
			{
				tmpPos = 0;
			}
			m_sB.SetScrollPos(tmpPos);
			m_pos = tmpPos;
			UpdateData(FALSE);
			break;
		}
		case SB_LINERIGHT://向右的箭头
		{
			//获取滑块位置
			tmpPos = m_sB.GetScrollPos() + 1;
			if (tmpPos > 100)
			{
				tmpPos = 100;
			}
			m_sB.SetScrollPos(tmpPos);
			m_pos = tmpPos;
			UpdateData(FALSE);
			break;
		}
		case SB_PAGELEFT://左箭头与滑块之间
		{
			//获取滑块位置
			tmpPos = m_sB.GetScrollPos() - 5;
			if (tmpPos < 0)
			{
				tmpPos = 0;
			}
			m_sB.SetScrollPos(tmpPos);
			m_pos = tmpPos;
			UpdateData(FALSE);
			break;
		}
		case SB_PAGERIGHT://右箭头与滑块之间
		{
			//获取滑块位置
			tmpPos = m_sB.GetScrollPos() + 5;
			if (tmpPos > 100)
			{
				tmpPos = 100;
			}
			m_sB.SetScrollPos(tmpPos);
			m_pos = tmpPos;
			UpdateData(FALSE);
			break;
		}
		default:
			break;
		}
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
