#ifndef EngineController_h
#define EngineController_h

#include "Arduino.h"

class EngineController
{
    public:
    EngineController();
    void startEngine(unsigned int speed, unsigned long time = 0);
    void stopEngine();
};

#endif /* EngineController_h */
