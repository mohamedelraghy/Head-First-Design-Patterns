#include "Duck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include <iostream>
#include <memory>

using namespace std;


class MallardDuck : public Duck {
	public:
		MallardDuck();
		void display() const override { cout << "I'm a real Mallard Duck" << endl; }
};

inline
MallardDuck::MallardDuck() {
	quackBehavior = make_unique<Quack>(); 
	flyBehavior = make_unique<FlyWithWings>();
}