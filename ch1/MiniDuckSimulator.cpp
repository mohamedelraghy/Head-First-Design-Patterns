#include "MallardDuck.h"
#include "ModelDuck.h"

#include<iostream>
#include <memory>
using namespace std;



int main(){

    MallardDuck md;
    md.display();
    md.performFly();
    md.performQuack();
    cout << "===========" << endl;
    ModelDuck modelduck;
    modelduck.display();
    modelduck.performFly();
    modelduck.performQuack();
    
}