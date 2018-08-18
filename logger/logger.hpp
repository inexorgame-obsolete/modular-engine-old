#include <fruit/fruit.h>
#include <iostream>

#pragma once

class Logger {

public:
    virtual void write(std::string s) = 0;

};

extern fruit::Component<Logger> getLoggerComponent();
