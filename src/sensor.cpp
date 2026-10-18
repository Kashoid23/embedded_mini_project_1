#include <Arduino.h>

#include "config.h"

namespace Sensor {
    void begin() {
        analogReadResolution(Config::kResolution);
    }

    int readLdr() {
        return analogRead(Config::kLdrPin);
    }
}
