#include <fruit/fruit.h>

#include "null_logger.hpp"

namespace inexor {
namespace util {

class NullLogger : public Logger {
public:
    INJECT(NullLogger()) = default;

    /// The log pattern
    std::string pattern;

    /// The log level
    int level;

    virtual void debug(std::string message) override {
    }

    virtual void info(std::string message) override {
    }

    virtual void warn(std::string message) override {
    }

    virtual void error(std::string message) override {
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

fruit::Component<Logger> getNullLoggerComponent() {
    return fruit::createComponent()
            .bind<Logger, NullLogger>();
}

}
}
