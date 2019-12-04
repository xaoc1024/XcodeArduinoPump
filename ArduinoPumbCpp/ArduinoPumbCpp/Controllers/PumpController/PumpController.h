#ifndef PumpController_h
#define PumpController_h

#include "Arduino.h"
#include "EngineController.h"
#include "I2CMemoryManager.h"
#include "KeyPressable.h"
#include "LiquidCrystal.h"

class PumpControllerDelegate {
public:
    virtual void pumpControllerDidPressMenu() = 0;
};

class PumpController: public KeyPressable {
public:
    PumpController(EngineController*, MemoryManager*, LiquidCrystal*);
    
    EngineController *engine;
    MemoryManager *memoryManager;
    LiquidCrystal *lcd;

    PumpControllerDelegate *delegate;

    // MARK: - KeyPressable
    void pressKey(KeyboardKey);

    void run();
    void stop();

    void applyCalibratedSpeedRatio(float);

private:
    PumpConfiguration pumpConfiguration;
    void increaseSpeed();
    void decreaseSpeed();
    void saveConfiguration();
};


#endif /* PumpController_h */
