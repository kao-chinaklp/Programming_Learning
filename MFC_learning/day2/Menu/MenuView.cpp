﻿
// MenuView.cpp: CMenuView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Menu.h"
#endif

#include "MenuDoc.h"
#include "MenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMenuView

IMPLEMENT_DYNCREATE(CMenuView, CView)

BEGIN_MESSAGE_MAP(CMenuView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMenuView 构造/析构

CMenuView::CMenuView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMenuView::~CMenuView()
{
}

BOOL CMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMenuView 绘图

void CMenuView::OnDraw(CDC* /*pDC*/)
{
	CMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMenuView 打印

BOOL CMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMenuView 诊断

#ifdef _DEBUG
void CMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuDoc* CMenuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuDoc)));
	return (CMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMenuView 消息处理程序

//鼠标左键按下
void CMenuView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//获取主菜单
	//CMenu* menu = GetMenu();

	//创建菜单项
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);

	//获取子菜单
	CMenu* subMenu = menu.GetSubMenu(0);

	//坐标转换
	ClientToScreen(&point);

	//子菜单作为快捷菜单，右键菜单
	subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON,
		point.x, point.y, this);

	CView::OnLButtonDown(nFlags, point);
}
