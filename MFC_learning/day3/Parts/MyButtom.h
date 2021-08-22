#pragma once

#include "resource.h"
#include "pch.h"
#include "afxwin.h"

class MyButtom : public CButton
{
public:
	MyButtom();
	virtual ~MyButtom();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

