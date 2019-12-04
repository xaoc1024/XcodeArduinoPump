#include "PumpController.h"

PumpController::PumpController(EngineController *engine, MemoryManager *memoryManager, LiquidCrystal* liquidCrystal) {
    this->engine = engine;
    this->memoryManager = memoryManager;
    this->lcd = liquidCrystal;

    pumpConfiguration = memoryManager->read();

    if (pumpConfiguration.canary != kDefaultPumpConfiguration.canary) {
        pumpConfiguration = kDefaultPumpConfiguration;
        memoryManager->write(kDefaultPumpConfiguration);
    }
}

// MARK: - KeyPressable
void PumpController::pressKey(KeyboardKey theKey) {
    switch (theKey) {
        case KeyboardKeySelect: {
            stop();
            delegate->pumpControllerDidPressMenu();
            break;
        }

        case KeyboardKeyUp:
            increaseSpeed();
            break;

        case KeyboardKeyDown:
            decreaseSpeed();
            break;

        default:
            break;
    }
}

void PumpController::run() {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("ML/H:");
    lcd->setCursor(0, 1);
    lcd->print(pumpConfiguration.millilitersPerHour);

    engine->startEngine((unsigned int)round(pumpConfiguration.millilitersPerHour * pumpConfiguration.speedToMillilitersRatio));
}

void PumpController::stop() {
    engine->stopEngine();
}

void PumpController::applyCalibratedSpeedRatio(float speedToMillilitersRatio) {
    pumpConfiguration.speedToMillilitersRatio = speedToMillilitersRatio;
    saveConfiguration();
}

void PumpController::increaseSpeed() {
    pumpConfiguration.millilitersPerHour += 1;
    saveConfiguration();
    this->run();
}

void PumpController::decreaseSpeed() {
    if (pumpConfiguration.millilitersPerHour > 1) {
        pumpConfiguration.millilitersPerHour -= 1;
        saveConfiguration();
        this->run();
    }
}

void PumpController::saveConfiguration() {
    memoryManager->write(pumpConfiguration);
}
