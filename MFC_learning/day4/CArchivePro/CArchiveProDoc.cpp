
// CArchiveProDoc.cpp: CCArchiveProDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CArchivePro.h"
#endif

#include "CArchiveProDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCArchiveProDoc

IMPLEMENT_DYNCREATE(CCArchiveProDoc, CDocument)

BEGIN_MESSAGE_MAP(CCArchiveProDoc, CDocument)
END_MESSAGE_MAP()


// CCArchiveProDoc 构造/析构

CCArchiveProDoc::CCArchiveProDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CCArchiveProDoc::~CCArchiveProDoc()
{
}

BOOL CCArchiveProDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CCArchiveProDoc 序列化

void CCArchiveProDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		//保存数据
		ar << num;
		for (int i = 0; i < num; i++)
		{
			ar << m_pt[i];
		}
	}
	else
	{
		// TODO: 在此添加加载代码
		ar >> num;
		for (int i = 0; i < num; i++)
		{
			ar >> m_pt[i];
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CCArchiveProDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CCArchiveProDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CCArchiveProDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CCArchiveProDoc 诊断

#ifdef _DEBUG
void CCArchiveProDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCArchiveProDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCArchiveProDoc 命令



void CCArchiveProDoc::DeleteContents()
{
	// TODO: 在此添加专用代码和/或调用基类

	memset(&m_pt, 0, sizeof(m_pt));

	this->num = 0;

	CDocument::DeleteContents();
}
