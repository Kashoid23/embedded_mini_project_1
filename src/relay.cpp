#include <Arduino.h>

#include "config.h"

#define RELAY_PIN_MODE OUTPUT
#define RELAY_DEFAULT_STATE LOW

namespace Relay {
    void begin() {
        pinMode(Config::kRelayPin, RELAY_PIN_MODE);
        digitalWrite(Config::kRelayPin, RELAY_DEFAULT_STATE);
    }

    void setState(bool state) {
        digitalWrite(Config::kRelayPin, state ? HIGH : RELAY_DEFAULT_STATE);
    }
}
