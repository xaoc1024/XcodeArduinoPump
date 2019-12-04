//
//  main.cpp
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/27/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#define XCODE

#include <iostream>
#include "Orchestrator.h"

int main(int argc, const char * argv[]) {
    I2CMemoryManager manager = I2CMemoryManager(0x50);
    EngineController engine = EngineController();
    LiquidCrystal lcd = LiquidCrystal(8, 9, 4, 5, 6, 7);

    PumpController pumpController = PumpController(&engine, &manager, &lcd);
    KeyboardManager keyboardManager = KeyboardManager();
    MenuController menuController = MenuController(&lcd);
    PumpCalibrator pumpCalibrator = PumpCalibrator(&engine, &lcd);

    Orchestrator orchestrator = Orchestrator(&pumpController, &keyboardManager, &menuController, &pumpCalibrator);

    for (int i = 0; i < 100; i++) {
        orchestrator.loop();
    }

    return 0;
}
