#include <fruit/fruit.h>
#include <iostream>

#include "app.hpp"
#include "logger_impl.hpp"
#include "sound_impl.hpp"

fruit::Component<Sound> getAppComponent() {
    return fruit::createComponent()
        .install(getLoggerImplComponent)
        .install(getSoundImplComponent);
}
