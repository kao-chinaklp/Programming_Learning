
// 画图View.cpp: C画图View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "画图.h"
#endif

#include "画图Doc.h"
#include "画图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C画图View

IMPLEMENT_DYNCREATE(C画图View, CView)

BEGIN_MESSAGE_MAP(C画图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C画图View 构造/析构

C画图View::C画图View() noexcept
{
	// TODO: 在此处添加构造代码

}

C画图View::~C画图View()
{
}

BOOL C画图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C画图View 绘图

void C画图View::OnDraw(CDC* pDC)
{
	C画图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen pen(PS_DASH, 10, RGB(255, 0, 0));

	CPen* oldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(10, 10);
	pDC->LineTo(120, 10);

	pDC->SelectObject(oldPen);

	//画圆形
	pDC->Ellipse(20, 20, 120, 120);

	//画刷
	CBrush brush(RGB(255, 0, 0));
	pDC->SelectObject(&brush);

	pDC->Ellipse(20, 20, 120, 120);

	//定义一个位图对象
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);//加载位图

	CBrush brush2(&bitmap);
	pDC->SelectObject(&brush2);
	pDC->Ellipse(120, 20, 240, 240);

	CFont font;
	font.CreatePointFont(1000, TEXT("楷体"));

	pDC->SelectObject(&font);

	pDC->TextOutW(100, 100, TEXT("HELLO"));

	// TODO: 在此处为本机数据添加绘制代码
}


// C画图View 打印

BOOL C画图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C画图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C画图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C画图View 诊断

#ifdef _DEBUG
void C画图View::AssertValid() const
{
	CView::AssertValid();
}

void C画图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C画图Doc* C画图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C画图Doc)));
	return (C画图Doc*)m_pDocument;
}
#endif //_DEBUG


// C画图View 消息处理程序


void C画图View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	MyPoint = point; //保存鼠标点击的坐标

	m_isPress = true;

	CView::OnLButtonDown(nFlags, point);
}


void C画图View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
#if 0
	//创建画家，指定绘画设备
	CClientDC dc(this);

	dc.MoveTo(MyPoint);
	dc.LineTo(point);
#endif

	m_isPress = false;

	CView::OnLButtonUp(nFlags, point);
}


void C画图View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (m_isPress == true)
	{
		//创建画家，指定绘画设备
		CClientDC dc(this);

		dc.MoveTo(MyPoint);
		dc.LineTo(point);

		//终点作为起点

		MyPoint = point;
	}

	CView::OnMouseMove(nFlags, point);
}
