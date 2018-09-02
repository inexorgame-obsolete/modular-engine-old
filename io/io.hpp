#pragma once

#include <string>

namespace inexor {
namespace io {

class IO {

public:

    virtual int get(int key) = 0;
    virtual void set(int key, int value) = 0;

};

}
}
