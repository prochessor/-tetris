#pragma once
#include "help.h"
#include "Shape.h"
#include <thread>
#include <conio.h>
#include <Windows.h>

class Board
{
	friend class Game;
private:
	Shape* s = new Shape[50]; //aggregation
	Block blocks[20][15];//composition
public:
	
	static void controlShape(Shape& s, int shapeNumber, int rotation);
	void displayBlocks(Block blocks[][15], Shape s[]);
	void giveBlockAttributes(Block blocks[][15]);
	bool moveValidation(Shape s[]);
	bool moveValidationC(Shape s[]);
	bool bringShapesDown(Shape s[],int turn =0);
	bool validLeftMove(Shape s[]);
	bool validRightMove(Shape s[]);
	bool moveValidationForL(Shape s[]);
	bool moveValidationForR(Shape s[]);
	void controlShapeDown();
	void input();
	void controlGame();
	void displayMenu();
	void displayGameOver();
	void timer();
	thread member3Thread() {
		return thread([=] { controlGame(); });
	}
	thread member4Thread() {
		return thread([=] { timer(); });
	}
	thread member1Thread() {
		return thread([=] { controlShapeDown(); });
	}
	thread member2Thread() {
		return thread([=] { input(); });
	}
};
