#include"pch.h"
#include "unit.h"
#include"CTool.h"
#include<iostream>
using namespace std;

void CUnit::show()
{
	CTool::gotoXY(u_X, u_Y);
	cout << ch;
}

void CUnit::erase()
{
	CTool::gotoXY(u_X, u_Y);
	cout << " ";
}

