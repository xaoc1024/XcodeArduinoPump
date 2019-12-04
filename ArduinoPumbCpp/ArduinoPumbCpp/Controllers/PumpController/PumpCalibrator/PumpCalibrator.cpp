#include "PumpCalibrator.h"

#define CALIBRATION_SPEED 6000 // TODO: set it correctly
#define MINUTE (60 * 1000)
#define HOUR (60 * MINUTE)
#define CALIBRATION_TIME MINUTE // ms

PumpCalibrator::PumpCalibrator(EngineController *engine, LiquidCrystal* liquidCrystal) {
    this->engine = engine;
    this->lcd = liquidCrystal;
}

void PumpCalibrator::calibrate() {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Calibrating...");

    engine->startEngine(CALIBRATION_SPEED, CALIBRATION_TIME);

    delay(CALIBRATION_TIME);
    printCalibration(calibratedVolume);
}

void PumpCalibrator::pressKey(KeyboardKey theKey) {
    switch (theKey) {
        case KeyboardKeyUp:
            increaseAmount();
            break;

        case KeyboardKeyDown:
            decreaseAmount();
            break;

        case KeyboardKeyLeft:
            if (calibrationMutliplier > 0.01) {
                calibrationMutliplier /= 10.0;
            }
            break;

        case KeyboardKeyRight:
            if (calibrationMutliplier < 100.0) {
                calibrationMutliplier *= 10.0;
            }
            break;

        case KeyboardKeySelect:
            delegate->pumpCalibratorDidFinish(CALIBRATION_SPEED / (calibratedVolume * (HOUR / float(CALIBRATION_TIME))));
            break;

        default:
            break;
    }
}

void PumpCalibrator::printCalibration(float calibration) {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("ML x");
    lcd->setCursor(5, 0);
    lcd->print(calibrationMutliplier);
    lcd->setCursor(0, 1);
    lcd->print(calibration);
}

void PumpCalibrator::increaseAmount() {
    calibratedVolume += calibrationMutliplier;
    printCalibration(calibratedVolume);
}

void PumpCalibrator::decreaseAmount() {
    if (calibratedVolume > 1) {
        calibratedVolume -= calibrationMutliplier;
        printCalibration(calibratedVolume);
    }
}
