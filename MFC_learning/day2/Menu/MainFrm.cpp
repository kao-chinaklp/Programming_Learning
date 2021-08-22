
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "Menu.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_TEST_A, &CMainFrame::OnUpdateTestA)
	ON_COMMAND(ID_TEST_B, &CMainFrame::OnTestB)
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
	m_bAutoMenuEnable = FALSE;
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

	//标志
	//获取菜单
	//获取主菜单
	CMenu* menu = GetMenu();

	//获取子菜单
	CMenu* fileMenu = menu->GetSubMenu(0);

	//标志“新建”
	//第一个参数由MF_BYPOSTION决定
	fileMenu->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);

	//标志“打开”
	//第一个参数由MF_BYCOMMAND决定
	fileMenu->CheckMenuItem(ID_FILE_OPEN, MF_BYCOMMAND | MF_CHECKED);

	//设置默认项，加粗，一个菜单只有一个
	//FALSE:ID
	//TRUE:位置
	fileMenu->SetDefaultItem(ID_FILE_SAVE, FALSE);//被屏蔽
	fileMenu->SetDefaultItem(3, TRUE);

	//变灰
	//需要把CFrameWnd::m_bAutoMenuEnable设置为false
	fileMenu->EnableMenuItem(5, MF_BYPOSITION | MF_DISABLED);

	//移除菜单
	SetMenu(NULL);

	//加载菜单
	CMenu menu2;

	menu2.LoadMenuW(IDR_MENU1);

	SetMenu(&menu2);

	//分离
	menu2.Detach();

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


//a的更新，内部自动更新
void CMainFrame::OnUpdateTestA(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_isUpdate == true)
	{
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}

//b的处理
void CMainFrame::OnTestB()
{
	// TODO: 在此添加命令处理程序代码
	m_isUpdate = !m_isUpdate;
}
