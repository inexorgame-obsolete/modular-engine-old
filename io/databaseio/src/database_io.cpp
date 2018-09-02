#include "database_io.hpp"

#include <lmdb++.h>

#include <fruit/fruit.h>
#include <iostream>


namespace inexor {
namespace io {

class DatabaseIO : public IO {
public:
    INJECT(DatabaseIO()) : env(lmdb::env::create()){
        // Create and open the LMDB environment
        env.set_mapsize(1UL * 1024UL * 1024UL * 1024UL); // 1 GB
        env.open("./example.mdb", 0, 0664);
    }
    lmdb::env env;
  
    /// The log pattern
    int key;
    /// The log pattern
    int value;


    virtual int get(int key) override {
      return 1;
    }

    virtual void set(int key, int value) override {
        /* Insert some key/value pairs in a write transaction: */
      auto wtxn = lmdb::txn::begin(env);
      auto dbi = lmdb::dbi::open(wtxn, "testdb");
      dbi.put(wtxn, "username", "jhacker");
      dbi.put(wtxn, "email", "jhacker@example.org");
      dbi.put(wtxn, "fullname", "J. Random Hacker");
      wtxn.commit();

      /* Fetch key/value pairs in a read-only transaction: */
      auto rtxn = lmdb::txn::begin(env, nullptr, MDB_RDONLY);
      auto cursor = lmdb::cursor::open(rtxn, dbi);
      std::string keystr, valuestr;
      while (cursor.get(keystr, valuestr, MDB_NEXT)) {
        std::printf("keystr: '%s', valuestr: '%s'\n", keystr.c_str(), valuestr.c_str());
      }
      cursor.close();
      rtxn.abort();
    }

};

fruit::Component<IO> getDatabaseIoComponent() {
    return fruit::createComponent()
            .bind<IO, DatabaseIO>();
}

}
}
