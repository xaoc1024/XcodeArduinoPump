#ifndef Definitions_h
#define Definitions_h

#define XCODE

struct PumpConfiguration {
    uint16_t canary;
    float millilitersPerHour;
    float speedCoeficient;
};

static PumpConfiguration kDefaultPumpConfiguration = {
    .canary = 0xD5A3,
    .millilitersPerHour = 20.0,
    .speedCoeficient = 100.0
};


#endif /* Definitions_h */
