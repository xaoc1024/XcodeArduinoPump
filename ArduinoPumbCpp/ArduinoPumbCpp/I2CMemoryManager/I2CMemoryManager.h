//
//  I2CMemoryManager.h
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/27/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#ifndef I2CMemoryManager_hpp
#define I2CMemoryManager_hpp

//#include <stdio.h>
#include <iostream>
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


#endif /* I2CMemoryManager_hpp */
