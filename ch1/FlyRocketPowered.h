#ifndef FLYROCKETPOWERED_H
#define FLYROCKETPOWERED_H

#include "FlyBehavior.h"

#include <iostream>
using namespace std;

class FlyRocketPowered : public FlyBehavior{
    public:
        void fly() override { cout << "I'm Flying with a rocket" << endl; }
};


#endif /*#ifndef FLYROCKETPOWERED_H*/