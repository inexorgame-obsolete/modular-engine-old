#include "database_io.hpp"

#include <lmdb++.h>

#include <fruit/fruit.h>
#include <iostream>
#include <string>

using std::string;

namespace inexor {
namespace io {

class DatabaseIO : public IO {
public:
    INJECT(DatabaseIO()) : env(lmdb::env::create())
    {
        // Create and open the LMDB environment
        env.set_mapsize(1UL * 1024UL * 1024UL); // 1 MB
        env.open("/tmp/example.mdb", 0, 0664);
        set("component", "flex");
        std::printf("set key and comp");
        string comp = get("component");
        std::printf("got: '%s'\n", comp.c_str());
        if (comp == "flex")
            set("component", "core");
    }
    lmdb::env env;

    virtual string get(string key) override {
        /* Fetch key/value pairs in a read-only transaction: */
        auto rtxn = lmdb::txn::begin(env, nullptr, MDB_RDONLY);
        auto dbi = lmdb::dbi::open(rtxn, "testdb");
        auto cursor = lmdb::cursor::open(rtxn, dbi);
        std::string value;
        while (cursor.get(key, value, MDB_NEXT)) {
          std::printf("key: '%s', value: '%s'\n", key.c_str(), value.c_str());
        }
        cursor.close();
        rtxn.abort();
        return value;
    }

    virtual void set(string key, string value) override {
        /* Insert some key/value pairs in a write transaction: */
      auto wtxn = lmdb::txn::begin(env);
      auto dbi = lmdb::dbi::open(wtxn, "testdb", MDB_CREATE);
      dbi.put(wtxn, key, value);
      wtxn.commit();
    }

};

fruit::Component<IO> getDatabaseIoComponent() {
    return fruit::createComponent()
            .bind<IO, DatabaseIO>();
}

}
}
