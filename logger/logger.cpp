#include <fruit/fruit.h>
#include <iostream>

#include "logger.hpp"

class LoggerImpl : public Logger {
public:
    INJECT(LoggerImpl()) = default;

    virtual void write(std::string s) override {
      std::cout << s;
    }
};


fruit::Component<Logger> getLoggerComponent() {
    return fruit::createComponent()
            .bind<Logger, LoggerImpl>();
}
