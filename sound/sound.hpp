#include <fruit/fruit.h>
#include <iostream>

#pragma once

class Sound {

public:
    virtual void doSomething() = 0;

};
extern fruit::Component<Sound> getSoundComponent();
