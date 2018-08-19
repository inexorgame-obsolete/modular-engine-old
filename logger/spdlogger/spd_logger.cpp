#include <fruit/fruit.h>
#include <iostream>

#include "spd_logger.hpp"

namespace inexor {
namespace util {

class SpdLogger : public Logger {
public:
    INJECT(SpdLogger()) = default;

    /// The spdlog instance
    std::shared_ptr<spdlog::logger> spdlog_logger;

    /// The log pattern
    std::string pattern;

    /// The log level
    int level;

    virtual void debug(std::string message) override {
      std::cout << message;
    }

    virtual void info(std::string message) override {
      std::cout << message;
    }

    virtual void warn(std::string message) override {
      std::cout << message;
    }

    virtual void error(std::string message) override {
      std::cout << message;
    }

    virtual int getLevel() override {
      return level;
    }

    virtual void setLevel(int level) override {
      this->level = level;
    }

    virtual std::string getPattern() override {
      return pattern;
    }

    virtual void setPattern(std::string pattern) override {
      this->pattern = pattern;
    }

};

fruit::Component<Logger> getSpdLoggerComponent() {
    return fruit::createComponent()
            .bind<Logger, SpdLogger>();
}

}
}
