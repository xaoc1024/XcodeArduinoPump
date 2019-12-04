#include "PumpCalibrator.h"

#define CALIBRATION_SPEED 6000 // TODO: set the appropriate number to make calibration process decent
#define MINUTE (60 * 1000) // in milliseconds
#define HOUR (60 * MINUTE) // in milliseconds
#define CALIBRATION_TIME MINUTE // in milliseconds

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
            if (calibrationStep > 0.01) {
                calibrationStep /= 10.0;
            }
            break;

        case KeyboardKeyRight:
            if (calibrationStep < 100.0) {
                calibrationStep *= 10.0;
            }
            break;

        case KeyboardKeySelect:
            if (delegate != NULL) {
                delegate->pumpCalibratorDidFinishWithSpeedToMillilitersRatio(CALIBRATION_SPEED / (calibratedVolume * (HOUR / float(CALIBRATION_TIME))));
            }
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
    lcd->print(calibrationStep);
    lcd->setCursor(0, 1);
    lcd->print(calibration);
}

void PumpCalibrator::increaseAmount() {
    calibratedVolume += calibrationStep;
    printCalibration(calibratedVolume);
}

void PumpCalibrator::decreaseAmount() {
    if ((calibratedVolume - calibrationStep) >= 1.0) {
        calibratedVolume -= calibrationStep;
        printCalibration(calibratedVolume);
    }
}
