#pragma once

struct SensorReading {
    uint16_t raw;
};

namespace Sensor {
    constexpr uint16_t kThresholdDark = 1000;
    constexpr uint16_t kThresholdLight = 2000;

    void begin();
    SensorReading readLdr();
}
