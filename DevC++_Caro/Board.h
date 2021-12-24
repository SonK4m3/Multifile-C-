#ifndef BOARD_H
#define BOARD_H

class Board
{	
	private:
		int** a;
		int n;
		int condition;
		int remains;
		
		// X
		int** X_main;
		int** X_side;
		int** X_row;
		int** X_col;
		
		//O
		int** O_main;
		int** O_side;
		int** O_row;
		int** O_col;
		
		int max_X;
		int max_O;
	public:
		Board();
		// n
		void set_n(int);
		int get_n();	
		
		// condition
		void set_condition(int);				
		int get_condition();			
		
		// remains
		void set_remains(int );
		int get_remains();
			
		// a	
		void set_a(int , int , int);
		int get_a(int , int);
		
		// O
		void set_max_O(int);
		int get_max_O();
		
		void set_O_main(int , int , int);
		int get_O_main(int , int);
		
		void set_O_side(int , int , int);
		int get_O_side(int , int);
		
		void set_O_row(int , int , int);
		int get_O_row(int , int);
		
		void set_O_col(int , int , int);
		int get_O_col(int , int);
		
		// X
		void set_max_X(int);
		int get_max_X();
		
		void set_X_main(int , int , int);
		int get_X_main(int , int);
		
		void set_X_side(int , int , int);
		int get_X_side(int , int);
		
		void set_X_row(int , int , int);
		int get_X_row(int , int);
		
		void set_X_col(int , int , int);
		int get_X_col(int , int);
};

#endif
