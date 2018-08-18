#pragma once

#include <fruit/fruit.h>
#include <iostream>

namespace inexor {
namespace util {

class Logger {

public:
    virtual void write(std::string s) = 0;

};

}
}
