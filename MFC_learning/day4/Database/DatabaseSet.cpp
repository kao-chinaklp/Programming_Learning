
// 07_DatabaseSet.cpp : CMy07_DatabaseSet 类的实现
//

#include "pch.h"
#include "Database.h"
#include "DatabaseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy07_DatabaseSet 实现

// 代码生成在 2016年3月19日, 16:50

IMPLEMENT_DYNAMIC(CDatabaseSet, CRecordset)

CDatabaseSet::CDatabaseSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_id = 0;
	m_name = L"";
	m_age = 0;
	m_score = 0;
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CDatabaseSet::GetDefaultConnect()
{
	return _T("Driver=MySQL ODBC 8.0 Unicode Driver;SERVER=127.0.0.1;UID=root;PWD=mima123;DATABASE=info;PORT=3306");
}

CString CDatabaseSet::GetDefaultSQL()
{
	return _T("[student]");
}

void CDatabaseSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[名字]"), m_name);
	RFX_Long(pFX, _T("[年龄]"), m_age);
	RFX_Long(pFX, _T("[成绩]"), m_score);

}
/////////////////////////////////////////////////////////////////////////////
// CMy07_DatabaseSet 诊断

#ifdef _DEBUG
void CDatabaseSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDatabaseSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

