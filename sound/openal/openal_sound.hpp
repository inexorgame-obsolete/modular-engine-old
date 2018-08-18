#pragma once

#include "sound.hpp"
#include "logger.hpp"

extern fruit::Component<fruit::Required<Logger>, Sound> getOpenAlSoundComponent();
