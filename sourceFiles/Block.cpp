#include "Block.h"
ostream& operator<<(ostream& out, Block b)
{

	myRects(b.x + 600, b.y + 60, b.x + 630, b.y + 90, b.color[0],b.color[1],b.color[2]);
	return out;
}
void Block::assignPositions(int p1, int p2)
{
	x = p1;
	y = p2;
}
void Block::giveColor(int r, int g, int b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}