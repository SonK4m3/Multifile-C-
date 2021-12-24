#include "Board.h"
#include<iostream>
using namespace std;

const int MAX = 9;
const int WINCONDITION_3 = 3;
const int WINCONDITION = 5;

Board::Board(){
	// a
	a = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   a[i] = new int[MAX];
	
	// X   
	X_main = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   X_main[i] = new int[MAX];
	   
	X_side = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   X_side[i] = new int[MAX];
	   
	X_row = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   X_row[i] = new int[MAX];
	   
	X_col = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   X_col[i] = new int[MAX];
	   
	// O
	O_main = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   O_main[i] = new int[MAX];
	   
	O_side = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   O_side[i] = new int[MAX];
	   
	O_row = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   O_row[i] = new int[MAX];
	   
	O_col = new int*[MAX];
	for(int i = 0; i<MAX; i++)
	   O_col[i] = new int[MAX];
}


//n
void Board::set_n(int n){
	this->n = n;
}
int Board::get_n(){
	return n;
}

// condition
void Board::set_condition(int condition){
	this->condition = condition;
}
int Board::get_condition(){
	return condition;
}

//remains
void Board::set_remains(int remains){
	this->remains = remains;
}
int Board::get_remains(){
	return remains;
}

// set & get a
void Board::set_a(int i, int j, int x){
	this->a[i][j] = x;
}
int Board::get_a(int i, int j){
	return a[i][j];
}

// O
void Board::set_max_O(int max_O){
	this->max_O = max_O;
}
int Board::get_max_O(){
	return max_O;
}

void Board::set_O_main(int i, int j, int x){
	this->O_main[i][j] = x;
}
int Board::get_O_main(int i, int j){
	return O_main[i][j];
}

void Board::set_O_side(int i, int j, int x){
	this->O_side[i][j] = x;
}
int Board::get_O_side(int i, int j){
	return O_side[i][j];
}

void Board::set_O_row(int i, int j, int x){
	this->O_row[i][j] = x;
}
int Board::get_O_row(int i, int j){
	return O_row[i][j];
}

void Board::set_O_col(int i, int j, int x){
	this->O_col[i][j] = x;
}
int Board::get_O_col(int i, int j){
	return O_col[i][j];
}

// X
void Board::set_max_X(int max_X){
	this->max_X = max_X;
}
int Board::get_max_X(){
	return max_X;
}

void Board::set_X_main(int i, int j, int x){
	this->X_main[i][j] = x;
}
int Board::get_X_main(int i, int j){
	return X_main[i][j];
}

void Board::set_X_side(int i, int j, int x){
	this->X_side[i][j] = x;
}
int Board::get_X_side(int i, int j){
	return X_side[i][j];
}

void Board::set_X_row(int i, int j, int x){
	this->X_row[i][j] = x;
}
int Board::get_X_row(int i, int j){
	return X_row[i][j];
}

void Board::set_X_col(int i, int j, int x){
	this->X_col[i][j] = x;
}
int Board::get_X_col(int i, int j){
	return X_col[i][j];
}
