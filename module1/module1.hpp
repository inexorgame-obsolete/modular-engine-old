#include <fruit/fruit.h>
#include <iostream>

#pragma once

class Module1 {

public:
    virtual void write(std::string s) = 0;

};

extern fruit::Component<Module1> getModule1Component();
