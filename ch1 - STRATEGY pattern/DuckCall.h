#ifndef DUCKCALL_H
#define DUCKCALL_H

#include "QuackBehavior.h"
#include "Quack.h"

#include <iostream>
#include <memory>
using namespace std;

class DuckCall {
    unique_ptr<QuackBehavior> quackBehavior = nullptr;

    public:
        DuckCall(){ quackBehavior = make_unique<Quack>(); }
        void disply() const { cout << "I'm not a duck" << endl; }
        void performQuack(){ quackBehavior->quack(); }
};

#endif  /*#ifndef DUCKCALL_H*/ 