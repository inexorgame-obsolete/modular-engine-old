#include <fruit/fruit.h>
#include <iostream>

#include <string>
#include "app.hpp"

using std::string;


int main() {
    fruit::Injector<inexor::io::IO> injector(getAppComponent);
    inexor::io::IO* io = injector.get<inexor::io::IO*>();
    // sound->doSomething();
    io->set("component", "flex");
    std::printf("set key and comp");
    string comp = io->get("component");
    std::printf("got: '%s'\n", comp.c_str());
    if (comp == "flex")
        io->set("component", "core");
    return 0;
}
