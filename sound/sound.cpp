#include <fruit/fruit.h>
#include <iostream>

#include "logger.hpp"
#include "sound.hpp"

class SoundImpl : public Sound {
private:
	Logger* logger;

public:
    INJECT(SoundImpl()) = default;

    virtual void doSomething() override {
    	logger->write("Hello world!\n");
    }
};


fruit::Component<Sound> getSoundComponent() {
    return fruit::createComponent()
            .install(getLoggerComponent);
}
