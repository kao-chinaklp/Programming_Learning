#pragma once


// m_Dlg 对话框

class m_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(m_Dlg)

public:
	m_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~m_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
