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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	int x = rand() % 400;
	int y = rand() % 400;

	//��ť�ƶ�
	this->MoveWindow(x, y, 48, 48);

	CButton::OnMouseMove(nFlags, point);
}
