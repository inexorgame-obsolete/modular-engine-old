#include <fruit/fruit.h>
#include <iostream>

#include "module1/module1.hpp"
#include "module2/module2.hpp"


int main() {
    fruit::Injector<Module2> injector(getModule2Component);
    Module2* module2 = injector.get<Module2*>();
    module2->doSomething();
    return 0;
}
