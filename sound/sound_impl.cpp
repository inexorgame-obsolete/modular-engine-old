#include <fruit/fruit.h>
#include <iostream>

#include "sound_impl.hpp"

class SoundImpl : public Sound {
private:
	Logger* logger;

public:
    INJECT(SoundImpl(Logger *logger)) : logger(logger) {}

    virtual void doSomething() override {
    	logger->write("Hello world!\n");
    }
};

fruit::Component<fruit::Required<Logger>, Sound> getSoundImplComponent() {
    return fruit::createComponent()
            .bind<Sound, SoundImpl>();
}
