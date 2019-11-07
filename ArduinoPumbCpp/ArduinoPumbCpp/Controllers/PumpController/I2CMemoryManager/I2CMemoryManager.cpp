#include "I2CMemoryManager.h"
#include "Wire.h"

I2CMemoryManager::I2CMemoryManager(int address){
    deviceAddress = address;

    Wire.begin();
    Wire.setClock(400000);
}

void I2CMemoryManager::write(PumpData data)  {
    uint8_t *dataPtr = (uint8_t*)&data;

    Wire.beginTransmission(deviceAddress);
    Wire.write(0);
    Wire.write(dataPtr, sizeof(PumpData));
    Wire.endTransmission();
}

PumpData I2CMemoryManager::read() {
    int sizeOfData = sizeof(PumpData);

    Wire.beginTransmission(deviceAddress);
    Wire.write(0);
    Wire.endTransmission();

    Wire.beginTransmission(deviceAddress);
    Wire.requestFrom(deviceAddress, sizeOfData);

    uint8_t reading[sizeOfData];

    for(int i = 0; i < sizeOfData; i++) {
        reading[i] = Wire.read();
    }
    
    PumpData *data;
    data = (PumpData*)reading;

    return *data;
}
