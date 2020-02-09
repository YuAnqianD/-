#include"pch.h"
#include "Game.h"
#include"unit.h"
#include"Snake.h"
#include "CFood.h"
#include"windows.h"
#include"stdlib.h"
#include"iostream"
using namespace std;

int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态


	system("color F0");		//控制台颜色分别是背景色，字颜色
	
	Game game1;
	game1.run();

	
	
	getchar();				//按任意键退出
	system("exit");
	return 0;
}
