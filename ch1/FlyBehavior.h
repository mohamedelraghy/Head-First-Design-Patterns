#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H

class FlyBehavior {

public:

    virtual ~FlyBehavior() = default;
    virtual void fly() = 0;
};

#endif 