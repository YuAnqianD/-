#include "pch.h"
#include<stdlib.h>
#include "CFood.h"
#include "Game.h"
#include"iostream"
using namespace std;
//vector<CUnit>*vec
void CFood::createpos(vector<CUnit>&vec)
{
	while (true)
	{
		int x = rand() % (KLENGTH - KSIDE * 3 ) + KSIDE+1;  //  区间(min,max）中的值
		int y = rand() % (KWIDTH - (KSIDE + 2)-KSIDE*2 ) + (KSIDE+2)+1;
		size_t i = 0;
		for (i = 0; i < vec.size(); i++)
		{
			if (x == vec.at(i).u_X && y == vec.at(i).u_Y)
			{
				//代表当前已经生成的位置在蛇身上
				break;
			}
		}
		if (i == vec.size())
		{
			u_X = x;
			u_Y = y;
			return;
		}
	}
	
}
