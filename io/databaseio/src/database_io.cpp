#include <fruit/fruit.h>
#include <iostream>

#include "database_io.hpp"

namespace inexor {
namespace io {

class DatabaseIO : public IO {
public:
    INJECT(DatabaseIO()) = default;
  
    /// The log pattern
    int key;
    /// The log pattern
    int value;


    virtual int get(int key) override {
      return value;
    }

    virtual void set(int key, int value) override {
      value = value;
    }

};

fruit::Component<IO> getDatabaseIoComponent() {
    return fruit::createComponent()
            .bind<IO, DatabaseIO>();
}

}
}
