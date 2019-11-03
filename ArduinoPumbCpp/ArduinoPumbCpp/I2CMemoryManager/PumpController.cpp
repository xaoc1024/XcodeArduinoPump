//
//  PumpController.cpp
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/28/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#include "PumpController.h"

static const uint16_t canary = 0xD5A3;

static const float expectedCallibratedMilliliters = 20.0;
static const float defaultCalibrationCoeficient = 100.0;

PumpController::PumpController() {
}

PumpController::PumpController(EngineController engine, MemoryManager memoryManager) {
    this->engine = engine;
    this->memoryManager = &memoryManager;

    this->actualCallibratedMilliliters = 0;
    this->calibrationCoeficient = 0;
    this->millilitersPerHour = 0;
}
