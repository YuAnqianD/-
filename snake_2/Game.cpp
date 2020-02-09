
#include "pch.h"
#include "Game.h"
#include "CFood.h"
#include "Snake.h"
#include <string>
#include"iostream"
using namespace std;


void Game::drawGameInfo()
{
	string Gname = "游戏名称：贪吃蛇";
	string Gauthor = "编写者：余安乾";
	cout << Gname << "\t" << Gauthor << "\t\t\t" << "当前等级：" << Level << "   当前得分：" << Score << "   当前关卡：" << Ground <<" |"<< endl;
}
void Game::drawGameArea()								//------------------画框框------------------
{
	for (int m = 0; m < (KWIDTH - KSIDE); m++)
	{
		if (m < KSIDE)
			cout << endl;
		else if (m == KSIDE || m == (KWIDTH - KSIDE - 1))
		{
			for (int i = 0; i < (KLENGTH - KSIDE); i++) //第一条边框和最后一条边框
			{
				if (i < KSIDE)
					cout << " ";
				else
					cout << "-";
			}
			cout << endl;
		}
		else if (m == (KSIDE + 1))
		{
			for (int j = 0; j < KSIDE; j++)
				cout << " ";
			cout << "|";
			drawGameInfo();
		}
		else if (m == (KSIDE + 2))
		{ 
			for (int n = 0; n < (KLENGTH - KSIDE); n++)
			{
				if (n < KSIDE)
					cout << " ";
				else if ((n == KSIDE) || (n == (KLENGTH - KSIDE - 1)))
					cout << "|";
				else
					cout << "-";
			}
			cout << endl;
		}
		else
		{ 
			for (int z = 0; z < (KLENGTH - KSIDE); z++)
			{
				if ((z == KSIDE) || (z == (KLENGTH - KSIDE - 1)))
					cout << "|";
				else
					cout << " ";
			}
			cout << endl;
		}
	}
}

void Game::changeInfo()								//------------------分数改变，回合改变------------------
{
	Score+=10;
	range++;
	if (range == 2)									//每吃两个就加速
	{
		Level++;
		if(S1.S_Speed>=60)
			S1.S_Speed -= 50;
		range = 0;
	}
}
void Game::result(int res)							//------------------输出失败或胜利------------------
{
	if (res == 1)
	{
		
		system("cls");
		CTool::gotoXY(43, 13);
		cout << "you lose";
	}
	else
	{
		system("cls");
		CTool::gotoXY(43, 13);
		cout << "you win";
	}
}
bool Game::checkFailed()
{
	for (int q = 4; q < S1.S_Body.size(); q++)
	{
		if (S1.S_Body[q].u_X == S1.S_Body[0].u_X  &&  S1.S_Body[q].u_Y == S1.S_Body[0].u_Y)
			return true;//result(1);
	}
	if (KSIDE == S1.S_Body[0].u_X ||
		(KLENGTH - KSIDE-2) == S1.S_Body[0].u_X ||
		(KSIDE + 2) == S1.S_Body[0].u_Y ||
		(KWIDTH - KSIDE - 1) == S1.S_Body[0].u_Y)
	{
		return true;//result(1);
	}
	else
		return false;
}
bool Game::checkWin()
{
	if (Score == 50)
		return true;
	else
		return false;
}
void Game::run()
{	
	drawGameArea();
	F1.createpos(S1.S_Body);
	F1.show();
	int s=0;
	while (true)
	{
		S1.move();
		if (S1.eatFood(F1))
		{
			changeInfo();
			system("cls");
			drawGameArea();
			F1.createpos(S1.S_Body);
			F1.show();
		}
		if (checkFailed())
		{	s = 1;break;
		}
		if (checkWin())
		{	break;}
	}
	result(s);
}
