#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "logger.hpp"

extern fruit::Component<Logger> getSpdLoggerComponent();
