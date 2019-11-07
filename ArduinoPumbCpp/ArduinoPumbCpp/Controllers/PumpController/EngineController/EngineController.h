//
//  EngineController.h
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/27/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#ifndef EngineController_h
#define EngineController_h

#include "Arduino.h"

class EngineController
{
    public:
    EngineController();
    void stopEngine();
    void startEngine(int speed);
};

#endif /* EngineController_h */
