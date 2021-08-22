
// TimeoutView.cpp: CTimeoutView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Timeout.h"
#endif

#include "TimeoutDoc.h"
#include "TimeoutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTimeoutView

IMPLEMENT_DYNCREATE(CTimeoutView, CView)

BEGIN_MESSAGE_MAP(CTimeoutView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CTimeoutView 构造/析构

CTimeoutView::CTimeoutView() noexcept
{
	// TODO: 在此处添加构造代码

}

CTimeoutView::~CTimeoutView()
{
}

BOOL CTimeoutView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTimeoutView 绘图

void CTimeoutView::OnDraw(CDC* /*pDC*/)
{
	CTimeoutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CTimeoutView 打印

BOOL CTimeoutView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTimeoutView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTimeoutView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTimeoutView 诊断

#ifdef _DEBUG
void CTimeoutView::AssertValid() const
{
	CView::AssertValid();
}

void CTimeoutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTimeoutDoc* CTimeoutView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTimeoutDoc)));
	return (CTimeoutDoc*)m_pDocument;
}
#endif //_DEBUG


// CTimeoutView 消息处理程序


int CTimeoutView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	//设置定时器
	//1:定时器id
	//100:时间间隔，(ms)
	//NULL:使用系统默认的处理参数，每隔500ms，触发WM_TIMER
	SetTimer(1, 100, NULL);

	return 0;
}


void CTimeoutView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (nIDEvent == 1)
	{
#if 0
		static int i = 0;
		i++;

		CString str;
		str.Format(TEXT("%d"), i);

		MessageBox(str);

		if (i == 5)
		{
			KillTimer(1);
		}
#endif
		static int w = 0;
		w += 5;

		CString str = TEXT("塑造自己的过程很痛，但是你可以得到一个更好的自己。");
		//获取字符串的长度
		CClientDC dc(this);
		CSize size = dc.GetTextExtent(str);
		//如果宽度大于字符串的宽度，重新开始
		if (w > size.cx)
		{
			w = 0;
			//刷新窗口
			Invalidate();
		}
		int x = 30;
		int y = 30;
		CRect rect(x, y, x + w, y + size.cy);

		//黑色写一次
		dc.TextOutW(x, y, str);

		//设置字体颜色
		dc.SetTextColor(RGB(255, 0, 0));

		dc.DrawText(str, &rect, DT_LEFT);
	}

	CView::OnTimer(nIDEvent);
}

