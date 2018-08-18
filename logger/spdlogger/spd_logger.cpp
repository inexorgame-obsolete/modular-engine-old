#include <fruit/fruit.h>
#include <iostream>

#include "spd_logger.hpp"

namespace inexor {
namespace util {

class SpdLogger : public Logger {
public:
    INJECT(SpdLogger()) = default;

    virtual void write(std::string s) override {
      std::cout << s;
    }
};

fruit::Component<Logger> getSpdLoggerComponent() {
    return fruit::createComponent()
            .bind<Logger, SpdLogger>();
}

}
}
