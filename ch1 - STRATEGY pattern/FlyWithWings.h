#include "FlyBehavior.h"
#include<iostream>
using namespace std;


class FlyWithWings : public FlyBehavior {
	public:
		void fly() override { cout << "I'm flying!!" << endl; }
};