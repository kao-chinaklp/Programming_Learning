
// EditorView.cpp: CEditorView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Editor.h"
#endif

#include "EditorDoc.h"
#include "EditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditorView

IMPLEMENT_DYNCREATE(CEditorView, CView)

BEGIN_MESSAGE_MAP(CEditorView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CEditorView 构造/析构

CEditorView::CEditorView() noexcept
{
	// TODO: 在此处添加构造代码

}

CEditorView::~CEditorView()
{
}

BOOL CEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEditorView 绘图

void CEditorView::OnDraw(CDC* /*pDC*/)
{
	CEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CEditorView 打印

BOOL CEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CEditorView 诊断

#ifdef _DEBUG
void CEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEditorDoc* CEditorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditorDoc)));
	return (CEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CEditorView 消息处理程序


int CEditorView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	//获取字体信息
	CClientDC dc(this);

	TEXTMETRICW tm;

	dc.GetTextMetrics(&tm);

	//继承于CWnd
	CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);//创建插入符

	ShowCaret();//显示

	return 0;
}


void CEditorView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	SetCaretPos(point);//移动插入符

	//保存点击坐标
	MyPoint = point;
	str.Empty();

	CView::OnLButtonDown(nFlags, point);
}

//点击键盘自动调用
void CEditorView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	if (nChar == VK_RETURN)//换行
	{
		str.Empty();
		//获取字体信息
		TEXTMETRICW tm;
		dc.GetTextMetrics(&tm);

		MyPoint.y = MyPoint.y + tm.tmHeight;
	}
	else if (nChar == VK_BACK)//退格
	{
		//获取背景色
		COLORREF color = dc.GetBkColor();

		//设置写字的颜色
		COLORREF oldColor = dc.SetTextColor(color);

		//背景色重写一次
		dc.TextOutW(MyPoint.x, MyPoint.y, str);

		//去掉最后一个字符
		str = str.Left(str.GetLength() - 1);

		dc.SetTextColor(oldColor);
	}
	else
	{
		str += (TCHAR)nChar;
	}

	CSize size = dc.GetTextExtent(str);//获取字符串长度

	int x = MyPoint.x + size.cx;
	int y = MyPoint.y;

	dc.TextOutW(MyPoint.x, MyPoint.y, str);

	SetCaretPos(CPoint(x, y));

	CView::OnChar(nChar, nRepCnt, nFlags);
}
