#include"pch.h"
#include "CTool.h"
#include<Windows.h>
void CTool::gotoXY(int x, int y)
{
	COORD point;
	point.X = x;
	point.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, point);
}