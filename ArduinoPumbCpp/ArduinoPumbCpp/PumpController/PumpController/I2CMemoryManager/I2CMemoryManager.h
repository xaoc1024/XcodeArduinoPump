#ifndef I2CMemoryManager_h
#define I2CMemoryManager_h

#include "Arduino.h"
#include "Definitions.h"

class MemoryManager {
public:
    virtual void write(PumpConfiguration data) = 0;
    virtual PumpConfiguration read() = 0;
};

class I2CMemoryManager: public MemoryManager
{
public:
    I2CMemoryManager(int deviceAddress);
    void write(PumpConfiguration data) override;
    PumpConfiguration read() override;

private:
    int deviceAddress;
};


#endif /* I2CMemoryManager_h */
