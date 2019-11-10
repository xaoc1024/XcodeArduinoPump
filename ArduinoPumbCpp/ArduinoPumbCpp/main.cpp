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
//#include "I2CMemoryManager.h"
#include "Processor.h"
using namespace std;



int main(int argc, const char * argv[]) {
    I2CMemoryManager manager = I2CMemoryManager(0x50);
    EngineController engine = EngineController();

    PumpController pumpController = PumpController(&engine, &manager);
    KeyboardManager keyboardManager = KeyboardManager();
    Processor processor = Processor(&pumpController, &keyboardManager);

    for (int i = 0; i < 100; i++) {
        processor.loop();
    }

    return 0;
}
