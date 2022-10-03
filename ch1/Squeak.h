#include "QuackBehavior.h"
#include <iostream>
using namespace std;

class Squeak: public QuackBehavior{
    public:
        void quack() override { cout << "Squeak" << endl; }
};