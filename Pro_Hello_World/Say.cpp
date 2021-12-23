#include "Say.h"
#include<iostream>
using namespace std;

Say::Say()
{
	mess = "Say something!";
}

Say::Say(string mess){
	this->mess = mess;
}

void Say::say(){
	cout << mess << endl;
}
