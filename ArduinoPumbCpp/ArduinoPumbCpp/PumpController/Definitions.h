#ifndef Definitions_h
#define Definitions_h

struct PumpConfiguration {
    uint16_t canary;
    float millilitersPerHour;
    float speedToMillilitersRatio;
};

static const PumpConfiguration kDefaultPumpConfiguration = {
    .canary = 0xD5A3,
    .millilitersPerHour = 20.0,
    .speedToMillilitersRatio = 100.0
};

static const unsigned int kCalibrationSpeed = 6000; // TODO: set the appropriate number to make calibration process decent
static const unsigned long kSecond = 1000; // in milliseconds
static const unsigned long kMinute = 60 * kSecond;
static const unsigned long kHour = 60 * kMinute;
static const unsigned long kCalibrationTime = kMinute;

#endif /* Definitions_h */
