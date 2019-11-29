#ifndef Definitions_h
#define Definitions_h

#define XCODE

struct PumpConfiguration {
    uint16_t canary;
    float millilitersPerHour;
    float calibrationCoeficient;
};

static PumpConfiguration kDefaultPumpConfiguration = {
    .canary = 0xD5A3,
    .millilitersPerHour = 20.0,
    .calibrationCoeficient = 100.0
};


#endif /* Definitions_h */
