#include "Init.h"
#include "Board.h"
#include "Player.h"
#include<iostream>
using namespace std;

void Init_player(Player& p1, Player& p2){
	cout << "Player 1 chon X hoac O:\n";
	
	while(cin >> p1){
		if(p1.get_c() == 'X' || p1.get_c() == 'O'){
			if(p1.get_c() == 'X'){
				cout << "Player 1 chon X - Player 2 chon O\n";
				p2.set_c('O');
			}
			else if(p1.get_c() == 'O'){
				cout << "Player 1 chon O - Player 2 chon X\n";
				p2.set_c('X');
			}
			break;
		}
		else	cout << "getInput lai ...\n";	
	}
	
	p1.set_in_turn('Y');
	p2.set_in_turn('N');
}

void Init(Board& board,Player& p1,Player& p2){
	board.Init_board();
	
	Init_player(p1, p2);
	
	board.Print_board();
}

