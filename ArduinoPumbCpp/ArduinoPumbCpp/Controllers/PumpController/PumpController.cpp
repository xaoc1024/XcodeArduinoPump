#include "PumpController.h"

PumpController::PumpController(EngineController *engine, MemoryManager *memoryManager, LiquidCrystal* liquidCrystal) {
    this->engine = engine;
    this->memoryManager = memoryManager;
    this->lcd = liquidCrystal;

    savedConfiguration = memoryManager->read();

    if (savedConfiguration.canary != kDefaultPumpConfiguration.canary) {
        savedConfiguration = kDefaultPumpConfiguration;
        memoryManager->write(kDefaultPumpConfiguration);
    }
}

// MARK: - KeyPressable
void PumpController::pressKey(KeyboardKey theKey) {
    
}

void PumpController::run() {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("ml/h:");
    lcd->setCursor(0,1);
    lcd->print(savedConfiguration.millilitersPerHour);

    engine->startEngine(savedConfiguration.millilitersPerHour * savedConfiguration.calibrationCoeficient);
}

void PumpController::stop() {
    engine->stopEngine();
}
