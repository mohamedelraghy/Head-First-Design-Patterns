#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include <iostream>
#include <memory>
using namespace std;

class Duck {

    public:
       
        virtual ~Duck() = default;
		virtual void display() const = 0; // pure virtual function
        void performQuack() const { quackBehavior->quack(); }
		void performFly() const { flyBehavior->fly(); }
        void swim() { cout << "All Ducks floats, even decoys!" << endl;}

    protected:
		unique_ptr<FlyBehavior> flyBehavior = nullptr;
		unique_ptr<QuackBehavior> quackBehavior = nullptr; // call the interfaces and it's objects
};

