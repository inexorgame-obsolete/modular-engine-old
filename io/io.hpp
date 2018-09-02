#pragma once

#include <string>

namespace inexor {
namespace io {

class IO {

public:

    virtual std::string get(std::string key) = 0;
    virtual void set(std::string key, std::string value) = 0;

};

}
}
