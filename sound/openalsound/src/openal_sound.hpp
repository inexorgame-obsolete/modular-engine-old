#pragma once

#include "sound.hpp"
#include "logger.hpp"

namespace inexor {
namespace sound {

extern fruit::Component<fruit::Required<inexor::util::Logger>, Sound> getOpenAlSoundComponent();

}
}
