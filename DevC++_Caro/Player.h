#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>

class Player
{	private:
		char c;
		char in_turn;
	public:
		Player();
		void set_c(char );
		void set_in_turn(char );
		char get_c();
		char get_in_turn();
};

std::istream& operator >> (std::istream& ,Player& );

#endif
