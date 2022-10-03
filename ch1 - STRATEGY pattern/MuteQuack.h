#include "QuackBehavior.h"
#include <iostream>
using namespace std;


class MuteQuack : public QuackBehavior{
    public:
        void quack() override { cout << "<< Silence >>" << endl; }
};