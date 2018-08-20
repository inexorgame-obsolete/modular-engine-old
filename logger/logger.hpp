#pragma once

#include <fruit/fruit.h>
#include <iostream>

namespace inexor {
namespace util {

/**
 * Describes the log level.
 * It is intentionally designed to be compliant with spdlog.
 * @see https://github.com/gabime/spdlog/blob/v1.x/include/spdlog/common.h
 */
enum level {
    trace = 0,
    debug = 1,
    info = 2,
    warn = 3,
    err = 4,
    critical = 5,
    off = 6
};

/**
 * The logger interface describes how loggers should behave
 */

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
