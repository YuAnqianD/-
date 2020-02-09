#pragma once
class CUnit
{
	
public:
	int  u_X;
	int u_Y;
	char ch;
	CUnit(int X = 10, int Y = 5, char CH ='$') :u_X(X), u_Y(Y), ch(CH) {};
	void  show();
	void erase();
};

