//
//  Processor.h
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/28/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#ifndef Processor_hpp
#define Processor_hpp

//#include <stdio.h>
#include <iostream>
#include "Arduino.h"
#include "PumpController.h"

class Processor
{
public:
    Processor();
    Processor(PumpController pumpController);
    PumpController controller;
};

#endif /* Processor_hpp */
