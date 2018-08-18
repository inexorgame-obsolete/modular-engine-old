#include <fruit/fruit.h>
#include <iostream>

#include "module1.hpp"

class Module1Impl : public Module1 {
public:
    INJECT(Module1Impl()) = default;

    virtual void write(std::string s) override {
      std::cout << s;
    }
};
