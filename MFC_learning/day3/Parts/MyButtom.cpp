#include "pch.h"
#include "MyButtom.h"

MyButtom::MyButtom()
{
}

MyButtom::~MyButtom()
{
}
BEGIN_MESSAGE_MAP(MyButtom, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void MyButtom::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	int x = rand() % 400;
	int y = rand() % 400;

	//按钮移动
	this->MoveWindow(x, y, 48, 48);

	CButton::OnMouseMove(nFlags, point);
}
