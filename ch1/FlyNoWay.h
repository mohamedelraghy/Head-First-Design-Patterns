#include "FlyBehavior.h"
#include<iostream>
using namespace std;

class FlyNoWay : public FlyBehavior {
    public:
        void fly() override { cout << "No fly .." << endl;  }
};
