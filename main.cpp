#include <fruit/fruit.h>
#include <iostream>

#include "app/app.hpp"


int main() {
    fruit::Injector<Sound> injector(getAppComponent);
    Sound* sound = injector.get<Sound*>();
    sound->doSomething();
    return 0;
}
