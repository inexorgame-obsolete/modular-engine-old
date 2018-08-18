#include <fruit/fruit.h>
#include <iostream>

#include "app.hpp"
#include "spd_logger.hpp"
#include "openal_sound.hpp"

fruit::Component<Sound> getAppComponent() {
    return fruit::createComponent()
        .install(getSpdLoggerComponent)
        .install(getOpenAlSoundComponent);
}
