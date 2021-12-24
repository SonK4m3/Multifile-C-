#ifndef PROCESS_H
#define PROCESS_H
#include<string>
#include "Player.h"
#include "Board.h"

bool isInt(std::string);

int Str_Int(std::string);

bool isFull(Board);

void Get_input(Board&, Player&, Player&, bool&, bool&);

void Set_main(Board&);

void Set_side(Board&);

void Set_row(Board&);

void Set_col(Board&);

void Set_max_X_O(Board&);

void Continue(bool&, Board&, Player&, Player&);

void Process(Board&, Player&, Player&, bool&);

#endif
