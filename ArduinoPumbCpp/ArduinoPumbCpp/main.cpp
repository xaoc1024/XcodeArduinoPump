//
//  main.cpp
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/27/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#define XCODE

#include <iostream>
#include "Wire.h"
#include "Arduino.h"
#include "LiquidCrystal.h"

//#include "I2CMemoryManager.h"
#include "Processor.h"
using namespace std;

int main(int argc, const char * argv[]) {
    I2CMemoryManager manager = I2CMemoryManager(0x50);
    EngineController engine = EngineController();
    LiquidCrystal lcd = LiquidCrystal(8, 9, 4, 5, 6, 7);

    PumpController pumpController = PumpController(&engine, &manager, &lcd);
    KeyboardManager keyboardManager = KeyboardManager();
    MenuController menuController = MenuController(&lcd);

    Processor processor = Processor(&pumpController, &keyboardManager, &menuController);

    for (int i = 0; i < 100; i++) {
        processor.loop();
    }

    return 0;
}
