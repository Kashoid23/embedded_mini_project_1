#pragma once

struct SensorReading {
    uint16_t raw;
};

namespace Sensor {
    constexpr uint16_t kThresholdDark = 1600;
    constexpr uint16_t kThresholdLight = 2200;

    void begin();
    SensorReading readLdr();
}
