#pragma once
#include "unit.h"
#include "CFood.h"
#include <vector>
using namespace std;
typedef enum { LEFT, RIGHT, UP, DOWN }Drections;

class Snake
{
public:
	Snake(Drections direction=RIGHT, int x = 50, int y = 20, int Length = 15, int Speed = 300, char pic = '*');
	~Snake();
	void move();
	bool eatFood(CFood & pFood);
	void showSnake();
	void eraseSnake();
	void growup();
	void getdirection();
public:

	int S_Length;
	int S_HeadX;
	int S_HeadY;
	int S_Speed;
	char S_Pic;
	Drections S_Direction;
	vector<CUnit>S_Body;
};

