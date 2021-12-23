#ifndef BOARD_H
#define BOARD_H

class Board
{	
	private:
		int **a;
		int n;
		int condition;
		int remains;
		
		int max_X;
		int max_O;
	public:
		Board();
		void Init_board();	
		void Print_board();
};

#endif
