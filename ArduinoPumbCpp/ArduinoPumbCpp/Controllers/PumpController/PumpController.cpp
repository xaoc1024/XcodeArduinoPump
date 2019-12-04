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
    lcd->print("ml/h:");
    lcd->setCursor(0, 1);
    lcd->print(pumpConfiguration.millilitersPerHour);

    engine->startEngine(round(pumpConfiguration.millilitersPerHour * pumpConfiguration.speedCoeficient));
}

void PumpController::stop() {
    engine->stopEngine();
}

void PumpController::calibrate() {

}

void PumpController::increaseSpeed() {
    pumpConfiguration.millilitersPerHour += 1;
    memoryManager->write(pumpConfiguration);
    this->run();
}

void PumpController::decreaseSpeed() {
    if (pumpConfiguration.millilitersPerHour > 1) {
        pumpConfiguration.millilitersPerHour -= 1;
        memoryManager->write(pumpConfiguration);
        this->run();
    }
}
