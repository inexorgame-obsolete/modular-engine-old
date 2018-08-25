#pragma once

#include "sound/sound.hpp"
#include "logger/logger.hpp"

namespace inexor {
namespace sound {

extern fruit::Component<fruit::Required<inexor::util::Logger>, Sound> getOpenAlSoundComponent();

}
}
