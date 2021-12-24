#include "Process.h"
#include "Player.h"
#include "Board.h"
#include "Init.h"
#include<bits/stdc++.h>
using namespace std;

bool isInt(string s){
	for(int i = 0; i < s.size(); i++)
		if(s[i] < '0' && s[i] > '9')
			return false;
	return true;	
}

int Str_Int(string s){
	int res = 0;
	for(int i = 0; i < s.size(); i++)
		res = res * 10 + s[i] - '0';
	return res;
}

bool isFull(Board board){
	return board.get_remains() == 0;
}

void Get_input(Board& board, Player &p1, Player &p2, bool& display_STOP, bool& game_STOP){
	if(p1.get_in_turn() == 'Y'){
		cout << p1.get_mess();
			
		string input_player;
			
		scanf("\n");
		getline(cin, input_player);
		
		int x = 0, y = 0;
		char ch;
		
		vector<string> v;
		stringstream arr(input_player);
		
		while(!arr.eof()){
			string tmp;
			arr >> tmp;
			v.push_back(tmp);
		}
		
		if(v.size() == 3 && isInt(v[0]) && isInt(v[1]) && v[2].size() == 1){
			x = Str_Int(v[0]);
			y = Str_Int(v[1]);
			ch = v[2][0];
			if(x >= 1 && x <= board.get_n() && y >= 1 && y <= board.get_n() && v[2][0] == p1.get_c() && board.get_a(x-1, y-1) == -1){
				if(ch == 'O')
					board.set_a(x-1, y-1, 0);
				else if(ch == 'X')
					board.set_a(x-1, y-1, 1);
				
				board.set_remains(board.get_remains() - 1);
				
				p1.set_in_turn('N');
				p2.set_in_turn('Y');
				
				if(display_STOP)	display_STOP = false;
			}
			else if(x < 1 || x > board.get_n() || y < 1 || y > board.get_n()){
				cout << "Hay danh o trong ban co, Xin nhap lai ...\n";
				display_STOP = true;
			}
			else if(board.get_a(x-1, y-1) != -1){
				cout << "O da duoc danh, Xin nhap lai ...\n";
				display_STOP = true;
			}
			else if(v[2][0] != p1.get_c()){
				cout << "Ban nhap sai X O, Xin nhap lai ...\n";
				display_STOP = true;
			}
			else{
				cout << "Sai du lieu, Xin nhap lai ...\n";
				display_STOP = true;
			}
		}
		else if(v.size() == 1 && v[0] == "exit"){
			cout << "exit game ...\n";
			display_STOP = true;
			game_STOP = true;
		}
		else{
			cout << "Sai du lieu, Xin nhap lai ...\n";
			display_STOP = true;
		}
	}
	else Get_input(board, p2, p1, display_STOP, game_STOP);
}

void Set_main(Board& b){
	int n = b.get_n();
	
	// set X main
	for(int i = n - 1; i >= 0 ; i--){
		int cnt = 0;
		int k = i;
		for(int j = 0; j < n - i; j ++){
			if(b.get_a(k, j) == 1)
				cnt++;
			else 
				cnt = 0;
			b.set_X_main(k, j, cnt);
			b.set_max_X(max(b.get_max_X(), cnt));
			k++;
		}
	}
	
	for(int j = 0; j < n; j++){
		int cnt = 0;
		int k = j;
		for(int i = 0; i < n - j; i++){
			if(b.get_a(i, k) == 1)
				cnt++;
			else 
				cnt = 0;
			b.set_X_main(i, k, cnt);
			b.set_max_X(max(b.get_max_X(), cnt));
			k++;
		}
	}
	
	// set O main
	for(int i = n - 1; i >= 0 ; i--){
		int cnt = 0;
		int k = i;
		for(int j = 0; j < n - i; j ++){
			if(b.get_a(k, j) == 0)
				cnt++;
			else 
				cnt = 0;
			b.set_O_main(k, j, cnt);
			b.set_max_O(max(b.get_max_O(), cnt));
			k++;
		}
	}
	
	for(int j = 0; j < n; j++){
		int cnt = 0;
		int k = j;
		for(int i = 0; i < n - j; i++){
			if(b.get_a(i, k) == 0)
				cnt++;
			else 
				cnt = 0;
			b.set_O_main(i, k, cnt);
			b.set_max_O(max(b.get_max_O(), cnt));
			k++;
		}
	}
	
}

void Set_side(Board& b){
	int n = b.get_n();

	// set X side
	for(int i = n - 1; i >= 0 ; i--){
		int cnt = 0;
		int k = i;
		for(int j = n - 1; j >= i; j --){
			if(b.get_a(k, j) == 1)
				cnt++;
			else 
				cnt = 0;
			b.set_X_side(k, j, cnt);
			b.set_max_X(max(b.get_max_X(), cnt));
			k++;
		}
	}
	
	for(int j = 0; j < n; j++){
		int cnt = 0;
		int k = j;
		for(int i = 0; i <= n - j; i++){
			if(b.get_a(i, k) == 1)
				cnt ++;
			else
				cnt = 0;
			b.set_X_side(i, k, cnt);
			b.set_max_X(max(b.get_max_X(), cnt));
			k--;
		}
	}
	
	// set O side
	for(int i = n - 1; i >= 0 ; i--){
		int cnt = 0;
		int k = i;
		for(int j = n - 1; j >= i; j --){
			if(b.get_a(k, j) == 0)
				cnt++;
			else 
				cnt = 0;
			b.set_O_side(k, j, cnt);
			b.set_max_O(max(b.get_max_O(), cnt));
			k++;
		}
	}
	
	for(int j = 0; j < n; j++){
		int cnt = 0;
		int k = j;
		for(int i = 0; i <= n - j; i++){
			if(b.get_a(i, k) == 0)
				cnt ++;
			else
				cnt = 0;
			b.set_O_side(i, k, cnt);
			b.set_max_O(max(b.get_max_O(), cnt));
			k--;
		}
	}
}

void Set_row(Board& b){
	int n = b.get_n();
	
	// set X row 
	for(int i = 0; i < n; i ++){
		int cnt = 0;
		for(int j = 0; j < n; j ++){
			if(b.get_a(i, j) == 1)
				cnt++;
			else 
				cnt = 0;
			b.set_X_row(i, j, cnt);
			b.set_max_X(max(b.get_max_X(), cnt));
		}
	} 
	
	// set O row
	for(int i = 0; i < n; i ++){
		int cnt = 0;
		for(int j = 0; j < n; j ++){
			if(b.get_a(i, j) == 0)
				cnt++;
			else 
				cnt = 0;
			b.set_O_row(i, j, cnt);
			b.set_max_O(max(b.get_max_O(), cnt));
		}
	} 		
}

void Set_col(Board& b){
	int n = b.get_n();

	// set X col 
	for(int j = 0; j < n; j ++){
		int cnt = 0;
		for(int i = 0; i < n; i ++){
			if(b.get_a(i, j) == 1)
				cnt++;
			else 
				cnt = 0;
			b.set_X_col(i, j, cnt);
			b.set_max_X(max(b.get_max_X(), cnt));
		}
	}	
	
	// set O col 
	for(int j = 0; j < n; j ++){
		int cnt = 0;
		for(int i = 0; i < n; i ++){
			if(b.get_a(i, j) == 0)
				cnt++;
			else 
				cnt = 0;
			b.set_O_col(i, j, cnt);
			b.set_max_O(max(b.get_max_O(), cnt));
		}
	}
}

void Continue(bool& game_STOP, Board& board, Player& p1, Player& p2){
	cout << "---------------------------\n";
	cout << "Nhap 1 de tiep tuc choi lai\n"
		 << "Nhap 0 de thoat.\n";
		 
	string a; cin >> a;
	if(a == "1")	Init(board, p1, p2);	
	else if(a == "0"){
		cout << "---------------\n"
			 << "Exit game.";
		game_STOP = true;
	}
	else {
		Continue(game_STOP, board, p1, p2);
	}	
}

void Set_max_X_O(Board& board){
	Set_main(board);
	Set_side(board);
	Set_row(board);
	Set_col(board);	
}

void Process(Board& board, Player& p1, Player& p2, bool& game_STOP){
	Set_max_X_O(board);
	
	if(board.get_max_O() == board.get_condition()){
		cout << "------------\n";
		if(p1.get_c() == 'O')
			cout << "Player 1 Win!\n";
		else
			cout << "Player 2 Win!\n";
		Continue(game_STOP, board, p1, p2);
		return;
	}
	
	if(board.get_max_X() == board.get_condition()){
		cout << "-------------\n";
		if(p1.get_c() == 'X')
			cout << "Player 1 Win!\n";
		else
			cout << "Player 2 Win!\n";
		Continue(game_STOP, board, p1, p2);
		return;
	}
	
	if(isFull(board)){
		cout << "-----------\n";
		cout << "Draw!\n";
		Continue(game_STOP, board, p1, p2);
		return;
	}
}
