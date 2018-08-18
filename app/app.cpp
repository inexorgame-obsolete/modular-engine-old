#include <fruit/fruit.h>
#include <iostream>

#include "app.hpp"
#include "spd_logger.hpp"
#include "openal_sound.hpp"

fruit::Component<inexor::sound::Sound> getAppComponent() {
    return fruit::createComponent()
        .install(inexor::util::getSpdLoggerComponent)
        .install(inexor::sound::getOpenAlSoundComponent);
}
