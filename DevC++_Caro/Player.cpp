#include "Player.h"
#include<iostream>
using namespace std;

Player::Player()
{
	c = 'N';
	in_turn = 'N';
}

istream& operator >> (istream& in,Player& p){
	char x;
	in >> x;
	p.set_c(x);
	return in;
}
		
void Player::set_c(char c){
	this->c = c;
}
		
void Player::set_in_turn(char in_turn){
	this->in_turn = in_turn;
}
		
char Player::get_c(){
	return c;
}
		
char Player::get_in_turn(){
	return in_turn;
}
