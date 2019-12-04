#ifndef PumpCalibrator_hpp
#define PumpCalibrator_hpp

#include "Arduino.h"
#include "EngineController.h"
#include "I2CMemoryManager.h"
#include "KeyPressable.h"
#include "LiquidCrystal.h"

class PumpCalibratorDelegate {
public:
    virtual void pumpCalibratorDidFinishWithSpeedToMillilitersRatio(float) = 0;
};

class PumpCalibrator: public KeyPressable {
public:
    PumpCalibrator(EngineController*, LiquidCrystal*);

    EngineController *engine;
    LiquidCrystal *lcd;

    PumpCalibratorDelegate *delegate;

    // MARK: - KeyPressable
    void pressKey(KeyboardKey);
    void calibrate();

private:
    float calibratedVolume = 1; // ml
    float calibrationStep = 1; // ml

    void printCalibration(float);
    void increaseAmount();
    void decreaseAmount();
};


#endif /* PumpCalibrator_hpp */
