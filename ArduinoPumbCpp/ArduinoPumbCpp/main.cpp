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
#include "I2CMemoryManager.h"

using namespace std;

I2CMemoryManager manager = I2CMemoryManager(0x50);

int main(int argc, const char * argv[]) {
    PumpData data = manager.read();
    return 0;
}
