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


#endif /* Definitions_h */
