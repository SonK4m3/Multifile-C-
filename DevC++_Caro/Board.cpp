#include "Board.h"
#include<iostream>
using namespace std;

const int MAX = 9;
const int WINCONDITION_3 = 3;
const int WINCONDITION = 5;

Board::Board(){
	a = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   a[i] = new int[MAX];
}

void Board::Init_board(){
	cout << "Nhap kich thuoc ban co:\n";
	while(cin >> n){
		if(n < 1 || n > MAX)
			cout << "Nhap lai kich thuoc ban co ...\n";
		else 
			break;
	}
	
	remains = n * n;
	condition = (n > 3) ? WINCONDITION : WINCONDITION_3;
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j++)
			a[i][j] = -1;
	}
}

void Board::Print_board(){
	for(int i = 0; i <= n; i ++){
		if(i == 0)	cout << "  ";
		else cout << " " << i << " ";
	}
		
	cout << endl;
	
	for(int i = 0; i < n; i ++){
		cout << i + 1<< " ";
		for(int j = 0; j < n; j ++){
			if(a[i][j] == -1)
				cout << " - ";	
			else if(a[i][j] == 1)
				cout << " X ";
			else if(a[i][j] == 0)
				cout << " O ";
		}
		cout << endl;
	}
}
