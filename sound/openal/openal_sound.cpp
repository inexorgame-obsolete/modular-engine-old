#include <fruit/fruit.h>
#include <iostream>

#include "openal_sound.hpp"

namespace inexor {
namespace sound {

class OpenAlSound : public Sound {
private:
	inexor::util::Logger* logger;

public:
    INJECT(OpenAlSound(inexor::util::Logger *logger)) : logger(logger) {}

    virtual void doSomething() override {
    	logger->info("Hello world!\n");
    }
};

fruit::Component<fruit::Required<inexor::util::Logger>, Sound> getOpenAlSoundComponent() {
    return fruit::createComponent()
            .bind<Sound, OpenAlSound>();
}

}
}
