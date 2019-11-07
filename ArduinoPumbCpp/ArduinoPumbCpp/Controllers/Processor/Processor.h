//
//  Processor.h
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/28/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#ifndef Processor_h
#define Processor_h

#include "Arduino.h"
#include "PumpController.h"
#include "KeyboardManager.h"
#include "LoopInterface.h"

class Processor: public LoopInterface, KeyboardManagerDelegate
{
public:
//    Processor();
    Processor(PumpController *pumpController, KeyboardManager *keyboardManager);

    PumpController *controller = NULL;
    KeyboardManager *keyboardManager = NULL;

    // MAKR: - LoopInterface interface
    void tick();

    // MAKR: - KeyboardManagerDelegate interface
    void keyaboardManagerDidReadTheKey(KeyboardKey);
};

#endif /* Processor_h */
