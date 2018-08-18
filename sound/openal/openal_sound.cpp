#include <fruit/fruit.h>
#include <iostream>

#include "openal_sound.hpp"

class OpenAlSound : public Sound {
private:
	Logger* logger;

public:
    INJECT(OpenAlSound(Logger *logger)) : logger(logger) {}

    virtual void doSomething() override {
    	logger->write("Hello world!\n");
    }
};

fruit::Component<fruit::Required<Logger>, Sound> getOpenAlSoundComponent() {
    return fruit::createComponent()
            .bind<Sound, OpenAlSound>();
}
