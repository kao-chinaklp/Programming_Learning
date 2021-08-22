
// 07_DatabaseSet.cpp : CMy07_DatabaseSet ���ʵ��
//

#include "pch.h"
#include "Database.h"
#include "DatabaseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy07_DatabaseSet ʵ��

// ���������� 2016��3��19��, 16:50

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
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û�������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	//RFX_Long(pFX, _T("[id]"), m_id);
	//RFX_Text(pFX, _T("[name]"), m_name);

}
/////////////////////////////////////////////////////////////////////////////
// CMy07_DatabaseSet ���

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

