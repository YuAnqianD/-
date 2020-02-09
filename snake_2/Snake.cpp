#include "pch.h"
#include"CTool.h"
#include "Snake.h"
#include <conio.h>
#include"unit.h"
#include"windows.h"
#include<iostream>
using namespace std;
Snake::Snake(Drections direction, int x, int y , int Length , int Speed , char pic )
{
	S_HeadX = x;
	S_HeadY = y;
	S_Length = Length;
	S_Direction = direction;
	S_Speed = Speed;
	S_Pic = pic;

	int tempX = 0;
	int tempY = 0;

	for (int i = 0; i < S_Length; i++)
	{
		switch (S_Direction)
		{
		case UP:
			tempX = S_HeadX;
			tempY = S_HeadY + i;
			break;
		case DOWN:
			tempX = S_HeadX;
			tempY = S_HeadY - i;
			break;
		case LEFT:
			tempX = S_HeadX + i;
			tempY = S_HeadY;
			break;
		case RIGHT:
			tempX = S_HeadX - i;
			tempY = S_HeadY;
			break;
		}
		CUnit unit(tempX, tempY, pic);
		S_Body.push_back(unit);
	}
}
Snake::~Snake()
{
}
void Snake::showSnake()								//------------------显示蛇身------------------
{
	for (int i = 0; i < S_Length; i++)
	{
		S_Body[i].show();
	}
	Sleep(S_Speed);
}

void Snake::eraseSnake()								//------------------擦除蛇身------------------
{
	for (int i = 0; i < S_Length; i++)
	{
		S_Body[i].erase();
	}
}
void Snake::growup()								//------------------蛇身加1------------------
{
	CUnit unit(0, 0, S_Pic);
	S_Body.push_back(unit);
	S_Length++;
}
bool Snake::eatFood(CFood & pFood)								//------------------蛇吃食物------------------
{
	if (S_Body[0].u_X == pFood.u_X  && S_Body[0].u_Y == pFood.u_Y)
	{
		growup();
		return true;
	}
	return false;
}


void Snake::getdirection()								//------------------键入方向------------------
{
	short u, d, l, r, s;
	u=GetAsyncKeyState(VK_UP);
	d=GetAsyncKeyState(VK_DOWN);
	l = GetAsyncKeyState(VK_LEFT);
	r = GetAsyncKeyState(VK_RIGHT);
	s = GetAsyncKeyState(VK_SPACE);
	if (u != 0)
	{
		if (S_Direction == RIGHT || S_Direction == LEFT)S_Direction = UP;
	}
	if (d != 0)
	{
		if (S_Direction == RIGHT || S_Direction == LEFT)S_Direction = DOWN;
	}
	if (l != 0)
	{
		if (S_Direction == UP || S_Direction == DOWN)S_Direction = LEFT;
	}
	if (r != 0)
	{
		if (S_Direction == UP || S_Direction == DOWN)S_Direction = RIGHT;
	}
	if (s != 0)
	{
		system("pause>>nul");
	}


}

void Snake::move()								//------------------蛇身移动------------------
{
	int s = 1;
	//while (s)
	//{
	eraseSnake();

	for (int i = S_Length - 2; i >= 0; i--)
	{
			S_Body[i + 1].u_X = S_Body[i].u_X;
			S_Body[i + 1].u_Y = S_Body[i].u_Y;
	}
	switch (S_Direction)
	{
			case UP:
				S_Body[0].u_Y--;
				break;
			case DOWN:
				S_Body[0].u_Y++;
				break;
			case LEFT:
				S_Body[0].u_X--;
				break;
			case RIGHT:
				S_Body[0].u_X++;
				break;
	}
	showSnake();
	getdirection();
	//Sleep(50);
		//}

		

	}
	

