#include "I2CMemoryManager.h"

#ifdef XCODE
#include "Wire.h"
#else
#include <Wire.h>
#endif

I2CMemoryManager::I2CMemoryManager(int address){
    deviceAddress = address;

    Wire.begin();
    Wire.setClock(400000);
}

void I2CMemoryManager::write(PumpConfiguration data)  {
    uint8_t *dataPtr = (uint8_t*)&data;

    Wire.beginTransmission(deviceAddress);
    Wire.write(0);
    Wire.write(dataPtr, sizeof(PumpConfiguration));
    Wire.endTransmission();
}

PumpConfiguration I2CMemoryManager::read() {
    int sizeOfData = sizeof(PumpConfiguration);

    Wire.beginTransmission(deviceAddress);
    Wire.write(0);
    Wire.endTransmission();

    Wire.beginTransmission(deviceAddress);
    Wire.requestFrom(deviceAddress, sizeOfData);

    uint8_t reading[sizeOfData];

    for(int i = 0; i < sizeOfData; i++) {
        reading[i] = Wire.read();
    }
    
    PumpConfiguration *data;
    data = (PumpConfiguration*)reading;

    return *data;
}
