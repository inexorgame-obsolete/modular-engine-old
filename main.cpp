#include <fruit/fruit.h>
#include <iostream>

#include "module1.hpp"
#include "module1.cpp"
#include "module2.hpp"
#include "module2.cpp"

fruit::Component<Module2> getModule2Component() {
    return fruit::createComponent()
        .bind<Module1, Module1Impl>()
        .bind<Module2, Module2Impl>();
}

int main() {
    fruit::Injector<Module2> injector(getModule2Component);
    Module2* module2 = injector.get<Module2*>();
    module2->doSomething();
    return 0;
}
