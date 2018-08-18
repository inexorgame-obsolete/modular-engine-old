#pragma once


// #include "inexor/network/SharedClass.hpp"
// #include "inexor/network/SharedVar.hpp"                     // for SharedVar

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#undef LOG_INFO  //conflicting between spdlog and cef
#undef LOG_WARNING

#include <array>
#include <iomanip>
#include <map>
#include <memory>                                           // for shared_ptr
#include <ostream>                                          // for operator<<
#include <string>                                           // for string
#include <vector>

#include <array>
#include <iomanip>
#include <map>
#include <memory>                                           // for shared_ptr
#include <ostream>                                          // for operator<<
#include <string>                                           // for string
#include <vector>

#include "logger.hpp"

namespace inexor {
namespace util {

extern fruit::Component<Logger> getSpdLoggerComponent();

}
}
