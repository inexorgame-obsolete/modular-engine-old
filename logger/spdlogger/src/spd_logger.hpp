#pragma once


// #include "inexor/network/SharedClass.hpp"
// #include "inexor/network/SharedVar.hpp"                     // for SharedVar

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "logger/logger.hpp"

namespace inexor {
namespace util {

#define DEFAULT_LOG_PATTERN "%H:%M:%S [%n] [%l] %v"

extern fruit::Component<Logger> getSpdLoggerComponent();

}
}
