#include "Init.h"
#include "Board.h"
#include "Player.h"
#include "Display.h"
#include<iostream>
using namespace std;

const int MAX = 9;
const int WINCONDITION_3 = 3;
const int WINCONDITION = 5;

void Init_player(Player& p1, Player& p2){
	cout << "Player 1 chon X hoac O:\n";
	string input;
	
	while(cin >> input){
		if(input.size() == 1){
			p1.set_c(input[0]);
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
			else	cout << "Hay nhap dung du lieu!\n";		
		}
		else	cout << "Hay nhap dung du lieu!\n";		
	}
	
	p1.set_in_turn('Y');
	p2.set_in_turn('N');
}

void Init_board(Board& b){
	cout << "Nhap kich thuoc ban co:\n";
	int n;
	while(cin >> n){
		if(n < 1 || n > MAX)
			cout << "Nhap lai kich thuoc ban co ...\n";
		else{
			b.set_n(n);
			break;
		}
	}
	b.set_max_X(0);
	b.set_max_O(0);
	b.set_remains(n * n);
	b.set_condition((n > 3) ? WINCONDITION : WINCONDITION_3);
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j++)
			b.set_a(i, j, -1);
	}
}

void Init(Board& board,Player& p1,Player& p2){
	Init_board(board);
	
	Init_player(p1, p2);
	
	Print_board(board, false);
}

