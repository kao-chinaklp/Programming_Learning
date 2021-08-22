
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "CArchive.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_CARCHIVE_WRITE32773, &CMainFrame::OnCarchiveWrite32773)
	ON_COMMAND(ID_CARCHIVE_READ32774, &CMainFrame::OnCarchiveRead32774)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnCarchiveWrite32773()
{
	// TODO: 在此添加命令处理程序代码
	CFile file;
	BOOL isOk = file.Open(TEXT("../demo.txt"), CFile::modeCreate | CFile::modeWrite);
	if (isOk == false)
	{
		return;
	}

	//和CArchive管理
	//CArchive对象是数据流，文件和CArchive绑定一起
	//store:存储，写东西
	CArchive ar(&file, CArchive::store);

	//和cout用法一样
	int a = 10;
	CString str = TEXT("ABC");
	TCHAR ch = 't';

	//箭头代表流向
	//数据流向ar，ar指向文件
	ar << a << str << ch;

	ar.Close();
	file.Close();
}


void CMainFrame::OnCarchiveRead32774()
{
	// TODO: 在此添加命令处理程序代码
	CFile file;
	BOOL isOk = file.Open(TEXT("../demo.txt"), CFile::modeRead);
	if (isOk == false)
	{
		return;
	}

	//和CArchive管理
	//CArchive对象是数据流，文件和CArchive绑定一起
	//load:加载
	CArchive ar(&file, CArchive::load);

	//和cout用法一样
	int a;
	CString str;
	TCHAR ch;

	//箭头代表流向
	//数据流向ar，ar指向文件，数据流 -> 变量
	ar >> a >> str >> ch;

	CString buf;
	buf.Format(TEXT("%d,%s,%c"), a, str, ch);
	MessageBox(buf);

	ar.Close();
	file.Close();
}
