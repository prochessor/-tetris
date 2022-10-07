#include "Board.h"
int p = 0;

int score = 0;
int timeOfDelay = 500;
int red, green, blue;
bool check = false;
bool gameOver = false;
bool check1 = false;
bool timeFinished = false;
void Board::controlShape(Shape& s, int shapeNumber, int rotation)
{
	if (s.shapeNumber == 0)
	{
		if (s.rotation == 1)
		{
			s.x = new int[4]{ s.v,s.v - 1,s.v,s.v + 1 };
			s.y = new int[4]{ s.h - 1,s.h,s.h,s.h };
		}
		else if (s.rotation == 2)
		{
			s.x = new int[4]{ s.v,s.v,s.v,s.v + 1 };
			s.y = new int[4]{ s.h - 1,s.h + 1,s.h,s.h };
		}
		else if (s.rotation == 3)
		{
			s.x = new int[4]{ s.v,s.v - 1,s.v,s.v + 1 };
			s.y = new int[4]{ s.h + 1,s.h,s.h,s.h };

		}
		else if (s.rotation == 4)
		{

			s.x = new int[4]{ s.v,s.v,s.v,s.v - 1 };
			s.y = new int[4]{ s.h - 1,s.h + 1,s.h,s.h };
		}
	}
	else if (s.shapeNumber == 1)
	{
		if (s.rotation == 1)
		{
			s.x = new int[4]{ s.v + 1,s.v - 1,s.v,s.v + 1 };
			s.y = new int[4]{ s.h - 1,s.h,s.h,s.h };
		}
		else if (s.rotation == 2)
		{
			s.x = new int[4]{ s.v + 1,s.v ,s.v,s.v };
			s.y = new int[4]{ s.h + 1,s.h - 1,s.h,s.h + 1 };

		}
		else if (s.rotation == 3)
		{

			s.x = new int[4]{ s.v - 1,s.v - 1,s.v,s.v + 1 };
			s.y = new int[4]{ s.h + 1,s.h,s.h,s.h };

		}
		else if (s.rotation == 4)
		{

			s.x = new int[4]{ s.v - 1,s.v ,s.v,s.v };
			s.y = new int[4]{ s.h - 1,s.h - 1,s.h,s.h + 1 };

		}
	}
	else if (s.shapeNumber == 2)
	{
		if (s.rotation == 1)
		{

			s.x = new int[4]{ s.v,s.v + 1,s.v,s.v - 1 };
			s.y = new int[4]{ s.h,s.h - 1,s.h - 1,s.h };
		}
		else if (s.rotation == 2)
		{
			s.x = new int[4]{ s.v,s.v + 1,s.v + 1,s.v };
			s.y = new int[4]{ s.h ,s.h ,s.h + 1,s.h - 1 };

		}
		else if (s.rotation == 3)
		{

			s.x = new int[4]{ s.v,s.v + 1,s.v,s.v - 1 };
			s.y = new int[4]{ s.h - 1,s.h - 1,s.h,s.h };

		}
		else if (s.rotation == 4)
		{

			s.x = new int[4]{ s.v,s.v + 1,s.v + 1,s.v };
			s.y = new int[4]{ s.h ,s.h ,s.h + 1,s.h - 1 };
		}
	}
	else if (s.shapeNumber == 3)
	{
		if (s.rotation == 1)
		{

			s.x = new int[4]{ s.v - 1,s.v,s.v + 1,s.v + 2 };
			s.y = new int[4]{ s.h,s.h,s.h,s.h };
		}
		else if (s.rotation == 2)
		{
			s.x = new int[4]{ s.v ,s.v,s.v,s.v };
			s.y = new int[4]{ s.h - 1,s.h,s.h + 1,s.h + 2 };

		}
		else if (s.rotation == 3)
		{

			s.x = new int[4]{ s.v - 1,s.v,s.v + 1,s.v + 2 };
			s.y = new int[4]{ s.h,s.h,s.h,s.h };

		}
		else if (s.rotation == 4)
		{

			s.x = new int[4]{ s.v ,s.v,s.v,s.v };
			s.y = new int[4]{ s.h - 1,s.h,s.h + 1,s.h + 2 };

		}
	}
	else if (s.shapeNumber == 4)
	{
		if (s.rotation == 1)
		{
			s.x = new int[3]{ s.v,s.v,s.v - 1 };
			s.y = new int[3]{ s.h - 1,s.h,s.h };
		}
		else if (s.rotation == 2)
		{
			s.x = new int[3]{ s.v - 1,s.v,s.v - 1 };
			s.y = new int[3]{ s.h - 1,s.h,s.h };

		}
		else if (s.rotation == 3)
		{

			s.x = new int[3]{ s.v,s.v - 1,s.v - 1 };
			s.y = new int[3]{ s.h,s.h,s.h + 1 };

		}
		else if (s.rotation == 4)
		{

			s.x = new int[3]{ s.v,s.v,s.v - 1 };
			s.y = new int[3]{ s.h + 1,s.h,s.h };

		}
	}
	else if (s.shapeNumber == 5)
	{
		s.x = new int[4]{ s.v,s.v,s.v - 1,s.v - 1 };
		s.y = new int[4]{ s.h - 1,s.h,s.h - 1,s.h };
	}

}
void Board::displayBlocks(Block blocks[][15], Shape s[])
{
	myRect(590, 0 + 60, 1210, 860, 255, 255, 255);

	for (int i = 0; i < 20; ++i)
	{

		for (int j = 0; j < 15; ++j)
		{
			for (int l = 0; l < p + 1; ++l)
			{
				for (int k = 0; k < s[l].numberOfBlocks; ++k)
				{

					if (j == s[l].x[k] && i == s[l].y[k])
					{
						cout << blocks[i][j];

					}
				}

			}
		}
	}
}
void Board::giveBlockAttributes(Block blocks[][15])
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{

			blocks[i][j].assignPositions(j * 40, i * 40);
		}
	}
}
bool Board:: moveValidation(Shape s[])
{
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < s[i].numberOfBlocks; ++j)
		{
			for (int k = 0; k < s[p].numberOfBlocks; ++k)
			{
				if (s[i].x[j] == s[p].x[k] && s[i].y[j] == s[p].y[k] + 1)
				{
					return false;

				}
			}

		}
	}
	for (int i = 0; i < s[p].numberOfBlocks; ++i)
	{
		if (s[p].y[i] + 1 == 20)
			return false;

	}
	return true;
}
bool Board:: moveValidationC(Shape s[])
{
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < s[i].numberOfBlocks; ++j)
		{
			for (int k = 0; k < s[p].numberOfBlocks; ++k)
			{
				if (s[i].x[j] == s[p].x[k] && s[i].y[j] == s[p].y[k])
				{
					return false;

				}
			}

		}
	}
	for (int i = 0; i < s[p].numberOfBlocks; ++i)
	{
		if (s[p].y[i] + 1 == 20)
			return false;

	}
	return true;
}
bool Board:: bringShapesDown(Shape s[],int turn)
{
	for (int i = 0; i < s[p].numberOfBlocks; ++i)
	{

		if (moveValidation(s) == false)
		{
			return false;
		}
	}

	for (int i = 0; i < s[p].numberOfBlocks; ++i)
	{
		if(turn==0)
		s[p].y[i]++;
		else
			s[p].y[i]--;

	}
	if(turn ==0)
	s[p].h++;
	else
		s[p].h--;

	return true;
}
bool Board:: validLeftMove(Shape s[])
{
	for (int i = 0; i < s[p].numberOfBlocks; ++i)
	{
		if (s[p].x[i] - 1 < 0)
			return false;
	}
	return true;
}
bool Board:: validRightMove(Shape s[])
{
	for (int i = 0; i < s[p].numberOfBlocks; ++i)
	{
		if (s[p].x[i] + 1 > 14)
			return false;
	}
	return true;
}
bool Board:: moveValidationForL(Shape s[])
{
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < s[i].numberOfBlocks; ++j)
		{
			for (int k = 0; k < s[p].numberOfBlocks; ++k)
			{
				if (s[i].x[j] == s[p].x[k] - 1 && s[i].y[j] == s[p].y[k])
				{
					return false;

				}
			}

		}
	}
	for (int i = 0; i < s[p].numberOfBlocks; ++i)
	{
		if (s[p].y[i] + 1 == 20)
			return false;

	}
	return true;
}
bool Board:: moveValidationForR(Shape s[])
{
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < s[i].numberOfBlocks; ++j)
		{
			for (int k = 0; k < s[p].numberOfBlocks; ++k)
			{
				if (s[i].x[j] == s[p].x[k] + 1 && s[i].y[j] == s[p].y[k])
				{
					return false;

				}
			}

		}
	}
	for (int i = 0; i < s[p].numberOfBlocks; ++i)
	{
		if (s[p].y[i] + 1 == 20)
			return false;

	}
	return true;
}
void Board::controlShapeDown()
{
	srand(time(0));

	check1 = false;
	while (bringShapesDown(s) && check1 == false && !timeFinished)
	{
		bringShapesDown(s, 1);
		s[p].giveShapeColor(blocks, 10, 10, 10);
		displayBlocks(blocks, s);
		bringShapesDown(s);
		s[p].giveShapeColor(blocks, red, green, blue);
		displayBlocks(blocks, s);
		if (bringShapesDown(s)==false)
		{
			bringShapesDown(s, 1);
		}
		else {
			bringShapesDown(s, 1);

			Sleep(timeOfDelay);
		}

	}
	myRects(600, 48, 1205, 870, 10, 10, 10);
	s[p].giveShapeColor(blocks, red, green, blue);
	displayBlocks(blocks, s);
	
	p++;
	score += 60;

	check = true;
}

void Board::input()
{
	check = false;
	while (check == false)
	{
		int key;
		if (isCursorKeyPressed(key))
		{

			if (key == 1 && validLeftMove(s) && moveValidationForL(s) == true)
			{
				for (int i = 0; i < s[p].numberOfBlocks; ++i)
				{
					s[p].x[i]--;
				}
				s[p].v--;

			}
			if (key == 2)
			{

				if (s[p].rotation <= 3)
					s[p].rotation++;
				else
					s[p].rotation = 1;
				if (moveValidationC(s) && moveValidation(s) && moveValidationForL(s) && moveValidationForR(s)) {
					controlShape(s[p], s[p].shapeNumber, s[p].rotation);
					score += 10;
				}
				else
				{
					if (s[p].rotation == 1)
					{
						s[p].rotation = 1;
					}
					else
						s[p].rotation--;
				}
			}
			if (key == 3 && validRightMove(s) && moveValidationForR(s) == true)
			{
				for (int i = 0; i < s[p].numberOfBlocks; ++i)
				{
					s[p].x[i]++;

				}
				s[p].v++;
			}
			if (key == 4)
			{
				timeOfDelay = 100;
				score += 60;

			}
			if (key == 5)
			{
				while (bringShapesDown(s));

				
				
				check1 = true;
				score += 30;
				timeOfDelay = 0;
			}

			if (key != 5) {

				myRects(600, 48, 1205, 870, 10, 10, 10);
				s[p].giveShapeColor(blocks, red, green, blue);
				displayBlocks(blocks, s);
			}
		}
	}

}
void Board::controlGame()
{

	while (!timeFinished)
	{
		red = rand() % 255 + 1;
		green = rand() % 255 + 1;
		blue = rand() % 255 + 1;
		s[p].giveShape();
		s[p].giveShapeColor(blocks, red, green, blue);
		gotoxy(0, 0); // to reset the cursor to origin to print score 

		cout << endl << endl << endl << endl << endl << endl << endl;;
		cout << "				S C O R E : " << score << endl;
		displayBlocks(blocks, s);
		if (moveValidationC(s) == false || moveValidation(s) == false)
		{
			Sleep(1000);
			gameOver = true;
			system("cls");
			return;
		}
		timeOfDelay = 500;
		Board* w = this;
		std::thread thread1 = w->member1Thread();
		std::thread thread2 = w->member2Thread();
		thread1.join();
		thread2.join();
	}


}
void Board::displayMenu()
{
	int x = 745, y = 400;
	int key = 0;
	int selection = 1;
	cout << endl;
	cout << "						    **************MADE BY Prochessor Zaki**************" << endl << endl << endl << endl << endl;
	cout << "\n                         MM        MM     AA      IIIIIIIII	NN     NN               MM        MM  EEEEEEEE  NN     NN  UU     UU";
	cout << "\n                         MMM      MMM    AAAA	     II		NNN    NN               MMM      MMM  EE	NNN    NN  UU	  UU";
	cout << "\n                         MM M    M MM   AA  AA	     II		NN  N  NN               MM M    M MM  EEEEEEEE  NN  N  NN  UU	  UU";
	cout << "\n                         MM  M  M  MM  AA AA AA      II		NN    NNN               MM  M  M  MM  EE	NN    NNN   U	  U";
	cout << "\n                         MM   M    MM AA      AA  IIIIIIIII	NN     NN               MM   M    MM  EEEEEEEE  NN     NN    U U U";
	cout << "\n\n\n\n\n\n";
	cout << "									PLAY GAME  " << endl << endl;
	cout << "								       INSTRUCTIONS" << endl << endl;
	cout << "									  QUIT" << endl << endl;
	while (1)
	{
		myRect(x, y, x + 200, y + 50, 0, 255, 255);

		bool pressed = isCursorKeyPressed(key);
		if (pressed)
		{
			if (key == 2)
			{
				if (y != 400)
				{
					myRect(x, y, x + 200, y + 50, 10, 10, 10);
					y -= 50;
					myRect(x, y, x + 200, y + 50, 0, 255, 255);
					selection--;

				}

			}
			if (key == 4)
			{
				if (y != 500)
				{
					myRect(x, y, x + 200, y + 50, 10, 10, 10);
					selection++;
					y += 50;
					myRect(x, y, x + 200, y + 50, 0, 255, 255);
				}
			}
			if (key == 5)
			{
				break;
			}
		}
	}
	if (selection == 1)
	{
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "				P O L I S H I N G   B L O C K S   T O   E N S U R E   Y O U   H A V E   S P A R K L I N G   E X P R I E N C E........" << endl;
		{
			Sleep(3000);
		}
		system("cls");

		giveBlockAttributes(blocks);
		Board* w = this;
		std::thread thread1 = w->member3Thread();
		std::thread thread2 = w->member4Thread();

		thread1.join();
		thread2.join();
		displayGameOver();
	}
	else if (selection == 2)
	{

	}

	else if (selection == 3)
	{
		exit(0);
	}
	_getch();
}
void Board::displayGameOver()
{
	system("cls");
	Sleep(500);
	system("cls");
	over();
	Sleep(3500);
	delete[] s;
	p = 0;
	s = new Shape[50];
	gameOver = false;
	score = 0;
	timeFinished = false;
	displayMenu();
}
void Board::timer()
{
	int x, y;
	x = 613 - 50;
	y = 22;
	myRect(598 - 50 + 3, 10, 1357 - 50, 40, 255, 255, 255); // this prints the bar of the timer
	for (int s = 60; s >= 0 && gameOver == false; --s)
	{

		myRectL(x, y, x + 12, y + 5, 0, 139, 139, 13);
		x += 12;
		Sleep(11500);
	}
	timeFinished = true;
	displayGameOver();

}