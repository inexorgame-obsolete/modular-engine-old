#include <fruit/fruit.h>
#include <iostream>

#include "app.hpp"
#include "logger/spdlogger/src/spd_logger.hpp"
// #include "logger/nulllogger/src/null_logger.hpp"
#include "sound/openalsound/src/openal_sound.hpp"
#include "io/databaseio/src/database_io.hpp"

fruit::Component<inexor::sound::Sound> getAppComponent() {
    return fruit::createComponent()
        .install(inexor::util::getSpdLoggerComponent)
        // .install(inexor::util::getNullLoggerComponent)
        .install(inexor::sound::getOpenAlSoundComponent);
        .install(inexor::io::getDatabaseIoComponent);
}
