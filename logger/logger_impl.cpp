#include <fruit/fruit.h>
#include <iostream>

#include "logger_impl.hpp"

class LoggerImpl : public Logger {
public:
    INJECT(LoggerImpl()) = default;

    virtual void write(std::string s) override {
      std::cout << s;
    }
};


fruit::Component<Logger> getLoggerImplComponent() {
    return fruit::createComponent()
            .bind<Logger, LoggerImpl>();
}
