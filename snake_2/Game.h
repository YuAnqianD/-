#pragma once
#include "Snake.h"
#include "CFood.h"

#define KLENGTH 100
#define KWIDTH 32
#define KSIDE 3
class Game
{
public:
	void run();
	bool checkFailed();
	bool checkWin();
	//bool checkLevel();
	void drawGameArea();
	void drawGameInfo();
	void changeInfo();
	void result(int res);

public:
	CFood F1;
	Snake S1;
	int Score=0;
	int Ground = 1;
	int Level=1;
	int range = 0;
	
};

