#include <fruit/fruit.h>
#include <iostream>

#include "app.hpp"


int main() {
    fruit::Injector<inexor::sound::Sound> injector(getAppComponent);
    inexor::sound::Sound* sound = injector.get<inexor::sound::Sound*>();
    sound->doSomething();
    return 0;
}
