#include "Duck.h"
#include "FlyNoWay.h"
#include "Quack.h"

#include <iostream>
#include <memory>
using namespace std;


class ModelDuck: public Duck {
    public:
        ModelDuck();
        void display() const override { cout << "I'm a model duck!" << endl; }
};

inline 
ModelDuck::ModelDuck(){
    flyBehavior = make_unique<FlyNoWay>();
    quackBehavior = make_unique<Quack>();
}