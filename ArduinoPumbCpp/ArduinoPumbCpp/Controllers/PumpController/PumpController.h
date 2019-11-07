//
//  PumpController.h
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/28/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#ifndef PumpController_h
#define PumpController_h

#include "Arduino.h"
#include "EngineController.h"
#include "I2CMemoryManager.h"

class PumpController {
public:
//    PumpController();
    PumpController(EngineController *engine, MemoryManager *memoryManager);
    EngineController *engine;
    MemoryManager *memoryManager;

private:
    float actualCallibratedMilliliters;
    float calibrationCoeficient;
    int millilitersPerHour;
};


#endif /* PumpController_h */
