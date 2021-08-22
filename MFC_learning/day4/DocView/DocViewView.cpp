
// DocViewView.cpp: CDocViewView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DocView.h"
#endif

#include "DocViewDoc.h"
#include "DocViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocViewView

IMPLEMENT_DYNCREATE(CDocViewView, CFormView)

BEGIN_MESSAGE_MAP(CDocViewView, CFormView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_RADIO1, &CDocViewView::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDocViewView::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDocViewView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDocViewView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDocViewView::OnBnClickedButton3)
END_MESSAGE_MAP()

// CDocViewView 构造/析构

CDocViewView::CDocViewView() noexcept
	: CFormView(IDD_DOCVIEW_FORM)
{
	// TODO: 在此处添加构造代码
	mui_Id = 0;
	mui_Name = TEXT("");
	mui_Age = 0;
	mui_Score = 0;
}

CDocViewView::~CDocViewView()
{
}

void CDocViewView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON2, m_ButtomPre);
	DDX_Control(pDX, IDC_BUTTON3, m_ButtomNext);
	DDX_Control(pDX, IDC_BUTTON2, m_ButtomPre);
	DDX_Text(pDX, IDC_EDIT1, mui_Id);
	DDX_Text(pDX, IDC_EDIT2, mui_Name);
	DDX_Text(pDX, IDC_EDIT3, mui_Age);
	DDX_Text(pDX, IDC_EDIT4, mui_Score);
}

BOOL CDocViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CDocViewView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//设置单选框状态，编辑那个被按下
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);

	//设置按钮状态
	OnBnClickedRadio1();
}


// CDocViewView 打印

BOOL CDocViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDocViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDocViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDocViewView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 在此处添加自定义打印代码
}


// CDocViewView 诊断

#ifdef _DEBUG
void CDocViewView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDocViewView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDocViewDoc* CDocViewView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocViewDoc)));
	return (CDocViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CDocViewView 消息处理程序

//点击编辑单选框
void CDocViewView::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ButtomNext.EnableWindow(FALSE);
	m_ButtomPre.EnableWindow(FALSE);
}


void CDocViewView::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ButtomNext.EnableWindow(TRUE);
	m_ButtomPre.EnableWindow(TRUE);
}

//添加
void CDocViewView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//把编辑区的内容更新到对应的变量中
	UpdateData(TRUE);
	Student* stu = new Student(mui_Id, mui_Name, mui_Age, mui_Score);

	//获取文档对象指针
	CDocViewDoc* pDoc = GetDocument();

	//从尾部添加节点
	pDoc->m_list.AddTail(stu);

	//获取最后一个元素节点
	pDoc->m_pos = pDoc->m_list.GetTailPosition();
}

//上一个
void CDocViewView::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取文档对象指针
	CDocViewDoc* pDoc = GetDocument();

	//获取上一个元素，pDox->m_pos会自动往上移动
	pDoc->m_list.GetPrev(pDoc->m_pos);

	//移动到头结点的上一个无效节点
	if (pDoc->m_pos == NULL)
	{
		//设置到尾节点
		pDoc->m_pos = pDoc->m_list.GetTailPosition();
	}
	//获取当前位置的元素
	Student *p = pDoc->m_list.GetAt(pDoc->m_pos);

	//把节点的值给变量
	mui_Id = p->m_id;
	mui_Name = p->m_name;
	mui_Age = p->m_age;
	mui_Score = p->m_score;

	UpdateData(FALSE);
}


void CDocViewView::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取文档对象指针
	CDocViewDoc* pDoc = GetDocument();

	//获取上一个元素，pDox->m_pos会自动往后移动
	pDoc->m_list.GetNext(pDoc->m_pos);

	//移动到头结点的下一个无效节点
	if (pDoc->m_pos == NULL)
	{
		//设置到尾节点
		pDoc->m_pos = pDoc->m_list.GetHeadPosition();
	}
	//获取当前位置的元素
	Student* p = pDoc->m_list.GetAt(pDoc->m_pos);

	//把节点的值给变量
	mui_Id = p->m_id;
	mui_Name = p->m_name;
	mui_Age = p->m_age;
	mui_Score = p->m_score;

	UpdateData(FALSE);
}
