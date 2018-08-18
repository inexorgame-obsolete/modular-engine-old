#include <fruit/fruit.h>
#include <iostream>

#include "module1.hpp"
#include "module2.hpp"

//class Module2 {
//public:
//    virtual void greet() = 0;
//};

class Module2Impl : public Module2 {

private:
	Module1* module1;

public:
    INJECT(Module2Impl(Module1* module1))
        : module1(module1) {
    }

    virtual void doSomething() override {
    	module1->write("Hello world!\n");
    }
};
