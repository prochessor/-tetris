#pragma once
#include <iostream>
#include "help.h"
using namespace std;
class Block
{
	friend ostream& operator<<(ostream& out, Block b);

private:
	int x=0;
	int y=0;
	int color[3]{ 200,200,200 };

public:
	Block() :x{ 0 }, y{ 0 } {}
	Block(int x, int y) :x{ x }, y{ y }{}
	void assignPositions(int p1, int p2);
	void giveColor(int r, int g, int b);
};
