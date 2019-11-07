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
