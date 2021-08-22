
// DatabaseView.cpp: CDatabaseView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Database.h"
#endif

#include "DatabaseDoc.h"
#include "DatabaseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDatabaseView

IMPLEMENT_DYNCREATE(CDatabaseView, CFormView)

BEGIN_MESSAGE_MAP(CDatabaseView, CFormView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CDatabaseView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDatabaseView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDatabaseView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CDatabaseView::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CDatabaseView::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CDatabaseView::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CDatabaseView::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CDatabaseView::OnBnClickedButton7)
END_MESSAGE_MAP()

// CDatabaseView 构造/析构

CDatabaseView::CDatabaseView() noexcept
	: CFormView(IDD_DATABASE_FORM)
{
	// TODO: 在此处添加构造代码

}

CDatabaseView::~CDatabaseView()
{
}

void CDatabaseView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);

	CDatabaseDoc* pDoc = GetDocument();

	DDX_Text(pDX, IDC_EDIT1, pDoc->m_id);
	DDX_Text(pDX, IDC_EDIT2, pDoc->m_name);
	DDX_Text(pDX, IDC_EDIT3, pDoc->m_age);
	DDX_Text(pDX, IDC_EDIT4, pDoc->m_score);
}

BOOL CDatabaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CDatabaseView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//打开数据库
	CDatabaseDoc* pDoc = GetDocument();

	//获取数据库对象及对象指针
	pSet = pDoc->GetMySet();

	//若没有打开，则打开
	if (pSet->IsOpen() == FALSE)
	{
		pSet->Open();
	}
}


// CDatabaseView 打印

BOOL CDatabaseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDatabaseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDatabaseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDatabaseView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 在此处添加自定义打印代码
}


// CDatabaseView 诊断

#ifdef _DEBUG
void CDatabaseView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDatabaseView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDatabaseDoc* CDatabaseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDatabaseDoc)));
	return (CDatabaseDoc*)m_pDocument;
}
#endif //_DEBUG


// CDatabaseView 消息处理程序

//上一个
void CDatabaseView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	pSet->MovePrev();

	CDatabaseDoc* pDoc = GetDocument();

	//如果是开始的前一个
	if (pSet->IsBOF())
	{
		//把记录集设置为最后一个
		pSet->MoveLast();
	}

	//pSet->Requery();

	pDoc->m_id = pSet->m_id;
	pDoc->m_name = pSet->m_name;
	pDoc->m_age = pSet->m_age;
	pDoc->m_score = pSet->m_score;

	UpdateData(FALSE);
}


void CDatabaseView::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	pSet->MoveNext();

	CDatabaseDoc* pDoc = GetDocument();

	//如果是开始的前一个
	if (pSet->IsEOF())
	{
		//把记录集设置为最后一个
		pSet->MoveFirst();
	}

	//pSet->Requery();

	pDoc->m_id = pSet->m_id;
	pDoc->m_name = pSet->m_name;
	pDoc->m_age = pSet->m_age;
	pDoc->m_score = pSet->m_score;

	UpdateData(FALSE);
}

//添加记录
void CDatabaseView::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//数据库添加空记录
	pSet->AddNew();

}

//确定
void CDatabaseView::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDatabaseDoc* pDoc = GetDocument();

	pSet->m_id = pDoc->m_id;
	pSet->m_name = pDoc->m_name;
	pSet->m_age = pDoc->m_age;
	pSet->m_score = pDoc->m_score;

	//更新到数据库
	if (pSet->CanUpdate())
	{
		pSet->Update();
	}
}

//修改
void CDatabaseView::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	pSet->Edit();

	UpdateData(TRUE);
	CDatabaseDoc* pDoc = GetDocument();

	pSet->m_id = pDoc->m_id;
	pSet->m_name = pDoc->m_name;
	pSet->m_age = pDoc->m_age;
	pSet->m_score = pDoc->m_score;

	//更新到数据库
	if (pSet->CanUpdate())
	{
		pSet->Update();
	}
}


void CDatabaseView::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	pSet->Delete();

	pSet->Requery();

	//更新到数据库
	if (pSet->CanUpdate())
	{
		pSet->Update();
	}
}

//过滤
void CDatabaseView::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	pSet->m_strFilter = ("年龄 > 18");

	pSet->Requery();
}


void CDatabaseView::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	//pSet->m_strSort = TEXT("年龄");//升序

	pSet->m_strSort = TEXT("年龄 desc");//降序

	pSet->Requery();
}
