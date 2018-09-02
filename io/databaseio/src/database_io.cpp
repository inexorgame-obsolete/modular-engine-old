#include <fruit/fruit.h>
#include <iostream>

#include "database_io.hpp"

namespace inexor {
namespace io {

class DatabaseIO : public IO {
public:
    INJECT(DatabaseIO()) = default;
  
    /// The log pattern
    std::string key;
    /// The log pattern
    std::string value;


    virtual int get(int key) override {
      return value;
    }

    virtual void set(int key, int value) override {
      value = value;
    }

};

fruit::Component<Logger> getDatabaseIoComponent() {
    return fruit::createComponent()
            .bind<IO, DatabaseIO>();
}

}
}
