#include "PumpCalibrator.h"
#include "Definitions.h"

PumpCalibrator::PumpCalibrator(EngineController *engine, LiquidCrystal* liquidCrystal) {
    this->engine = engine;
    this->lcd = liquidCrystal;
}

void PumpCalibrator::calibrate() {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Calibrating...");

    engine->startEngine(kCalibrationSpeed, kCalibrationTime);

    delay(kCalibrationTime);
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
                delegate->pumpCalibratorDidFinishWithSpeedToMillilitersRatio(kCalibrationSpeed / (calibratedVolume * (kHour / float(kCalibrationTime))));
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
