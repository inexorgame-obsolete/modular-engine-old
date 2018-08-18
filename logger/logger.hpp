#pragma once

#include <fruit/fruit.h>
#include <iostream>

class Logger {

public:
    virtual void write(std::string s) = 0;

};
