#ifndef Definitions_h
#define Definitions_h

struct PumpConfiguration {
    uint16_t canary;
    float millilitersPerHour;
    float speedToMillilitersRatio;
};

static PumpConfiguration kDefaultPumpConfiguration = {
    .canary = 0xD5A3,
    .millilitersPerHour = 20.0,
    .speedToMillilitersRatio = 100.0
};

static unsigned int kCalibrationSpeed = 6000; // TODO: set the appropriate number to make calibration process decent
static unsigned long kSecond = 1000; // in milliseconds
static unsigned long kMinute = 60 * kSecond;
static unsigned long kHour = 60 * kMinute;
static unsigned long kCalibrationTime = kMinute;

#endif /* Definitions_h */
