#include <bits/stdc++.h>
#include "Init.h"
//#include "Process.h"
#include "Display.h"

using namespace std;

int main() {
	Board board;
	
	Player player1, player2;
	
	Init(board, player1, player2);	
	
	// display // 
	
	Display(board, player1, player2);
	
	return 0;
}
