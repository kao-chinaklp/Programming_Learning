
// CArchiveProView.cpp: CCArchiveProView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CArchivePro.h"
#endif

#include "CArchiveProDoc.h"
#include "CArchiveProView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCArchiveProView

IMPLEMENT_DYNCREATE(CCArchiveProView, CView)

BEGIN_MESSAGE_MAP(CCArchiveProView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CCArchiveProView 构造/析构

CCArchiveProView::CCArchiveProView() noexcept
{
	// TODO: 在此处添加构造代码

}

CCArchiveProView::~CCArchiveProView()
{
}

BOOL CCArchiveProView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCArchiveProView 绘图

void CCArchiveProView::OnDraw(CDC* pDC)
{
	CCArchiveProDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < pDoc->num; i++)
	{
		pDC->Ellipse(pDoc->m_pt[i].x - 5, pDoc->m_pt[i].y - 5, pDoc->m_pt[i].x + 5, pDoc->m_pt[i].y + 5);
	}
}


// CCArchiveProView 打印

BOOL CCArchiveProView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCArchiveProView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCArchiveProView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCArchiveProView 诊断

#ifdef _DEBUG
void CCArchiveProView::AssertValid() const
{
	CView::AssertValid();
}

void CCArchiveProView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCArchiveProDoc* CCArchiveProView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCArchiveProDoc)));
	return (CCArchiveProDoc*)m_pDocument;
}
#endif //_DEBUG


// CCArchiveProView 消息处理程序


void CCArchiveProView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//获取文档类对象指针
	CCArchiveProDoc* pDoc = GetDocument();

	//不能超过200
	if (pDoc->num > 199)
	{
		pDoc->num = 199;
		return;
	}

	pDoc->m_pt[pDoc->num] = point;

	pDoc->num++;

	//每点完一个点，绘图
	Invalidate(); //->OnDraw()


	CView::OnLButtonDown(nFlags, point);
}
