
#pragma once
#include "unit.h"
#include"CTool.h"
#include <vector>
using namespace std;

class CFood :public CUnit
{
public:
	CFood(int X = 10, int Y = 5, char CH = '&') {};
	void createpos(vector<CUnit>&vec);

};