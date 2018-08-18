#include <fruit/fruit.h>
#include <iostream>

#pragma once

class Module2 {

public:
    virtual void doSomething() = 0;

};
extern fruit::Component<Module2> getModule2Component();
