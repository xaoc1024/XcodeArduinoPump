//
//  EngineController.h
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/27/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#ifndef EngineController_hpp
#define EngineController_hpp

//#include <stdio.h>
#include <iostream>
#include "Arduino.h"

class EngineController
{
    public:
    EngineController();
    void stopEngine();
    void startEngine(int speed);
};

#endif /* EngineController_hpp */
