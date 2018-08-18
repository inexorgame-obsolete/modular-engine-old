#include <fruit/fruit.h>
#include <iostream>

#include "sound/sound.hpp"


int main() {
    fruit::Injector<Sound> injector(getSoundComponent);
    Sound* sound = injector.get<Sound*>();
    sound->doSomething();
    return 0;
}
