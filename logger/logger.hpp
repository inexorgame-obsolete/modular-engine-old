#pragma once

#include <fruit/fruit.h>
#include <iostream>

namespace inexor {
namespace util {

class Logger {

public:

	virtual void debug(std::string message) = 0;
	virtual void info(std::string message) = 0;
	virtual void warn(std::string message) = 0;
	virtual void error(std::string message) = 0;

    virtual int getLevel() = 0;
    virtual void setLevel(int level) = 0;

    virtual std::string getPattern() = 0;
    virtual void setPattern(std::string pattern) = 0;

};

}
}
