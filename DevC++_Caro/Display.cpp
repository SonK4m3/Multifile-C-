#include "Display.h"
#include "Player.h"
#include "Board.h"
#include "Process.h"
#include<iostream>
using namespace std;

void Print_notice(bool display_STOP){
	if(!display_STOP){
		cout << "----------------------\n";
		cout << "Nhap exit de thoat.\n";
		cout << "----------------------\n";
	}	
}

void Print_board(Board board, bool display_STOP){
	if(!display_STOP){
		int n = board.get_n();
		for(int i = 0; i <= n; i ++){
			if(i == 0)	cout << "  ";
			else cout << " " << i << " ";
		}
			
		cout << endl;
		
		for(int i = 0; i < n; i ++){
			cout << i + 1<< " ";
			for(int j = 0; j < n; j ++){
				if(board.get_a(i, j) == -1)
					cout << " - ";	
				else if(board.get_a(i, j) == 1)
					cout << " X ";
				else if(board.get_a(i, j) == 0)
					cout << " O ";
			}
			cout << endl;
		}
	}
}

void Display(Board& board, Player& p1, Player& p2){
	
	bool display_STOP = false;
	bool game_STOP = false;
	p1.set_mess("Player 1 turn: \t");
	p2.set_mess("Player 2 turn: \t");
	
	while(!game_STOP){
		// get input
		Get_input(board, p1, p2, display_STOP, game_STOP);
		
		// print board
		Print_board(board, display_STOP);
		
		// print notice
		Print_notice(display_STOP);
		
		//process
		Process(board, p1, p2, game_STOP);
	}
	
	return;
}
