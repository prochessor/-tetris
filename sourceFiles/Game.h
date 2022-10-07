#pragma once
#include "Board.h"
#include "Block.h"
class Game
{
private:
	Board board;
public:
	void displayOpening() //this function is used to display "TETRIS" along with a rectangle in the very start
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\n                                      TTTTTTTTTTTT   EEEEEEEE   TTTTTTTTTTTT   RRRRRRR	  IIIIIIIII	 SSSSSSSS			";
		cout << "\n                                           TT        EE              TT        RR     R	     II    	SSS				";
		cout << "\n                                           TT        EEEEEEEE        TT        RR RR R	     II    	   SSS			";
		cout << "\n                                           TT        EE              TT        RR  RR	     II    	      SSS		";
		cout << "\n                                           TT        EEEEEEEE        TT        RR    RR	  IIIIIIIII	SSSSSSSS			";
		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t";
		for (int i = 0; i <= 1000; ++i) {
			myRect(230, 240, 1400, 540, 80, 160, 180);
			myRect(230 + 10, 240 + 10, 1400 - 10, 540 - 10, 80, 160, 180);
		}

		Sleep(5000);
		system("cls");
		board.displayMenu();
	}

};

