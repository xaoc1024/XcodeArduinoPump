#ifndef I2CMemoryManager_h
#define I2CMemoryManager_h

#include "Arduino.h"

struct PumpData {
    uint16_t canary;
    float milliliters;
    float calibrationCoeficient;
};

class MemoryManager {
public:
    virtual void write(PumpData data) = 0;
    virtual PumpData read() = 0;
};

class I2CMemoryManager: public MemoryManager
{
public:
    I2CMemoryManager(int deviceAddress);
    void write(PumpData data) override;
    PumpData read() override;

private:
    int deviceAddress;
};


#endif /* I2CMemoryManager_h */
