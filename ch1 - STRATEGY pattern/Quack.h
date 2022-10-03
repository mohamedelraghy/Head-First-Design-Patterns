#ifndef QUACK_H
#define QUACK_H

#include "QuackBehavior.h"
#include <iostream>

using namespace std;

class Quack : public QuackBehavior {   //class implement the interface
	public:
		void quack() override { cout << "Quack" << endl; }
};

#endif 	/* #ifndef QUACK_H */