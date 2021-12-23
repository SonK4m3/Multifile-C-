#include <iostream>
#include "Say.h"
using namespace std;

int main() {
	Say p, p1("Hello World!");
	cout << "p - ";
	p.say();
	
	cout << "p1 - ";
	p1.say();
	
	return 0;
}
