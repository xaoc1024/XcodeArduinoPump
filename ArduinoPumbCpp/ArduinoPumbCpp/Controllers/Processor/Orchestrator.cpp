#include "Orchestrator.h"

Orchestrator::Orchestrator(PumpController *pumpController, KeyboardManager *keyboardManager, MenuController *menuController, PumpCalibrator *pumpCalibrator) {
    this->pumpController = pumpController;
    this->pumpController->delegate = this;

    this->keyboardManager = keyboardManager;
    this->keyboardManager->delegate = this;

    this->menuController = menuController;
    this->menuController->delegate = this;
    this->menuController->showMenu();
    this->currentKeyHandler = menuController;

    this->pumpCalibrator = pumpCalibrator;
    pumpCalibrator->delegate = this;
}

// MAKR: - LoopInterface interface

void Orchestrator::loop() {
    keyboardManager->loop();
}

// MAKR: - KeyboardManagerDelegate
void Orchestrator::keyboardManagerDidReadKey(KeyboardKey theKey) {
    currentKeyHandler->pressKey(theKey);
}

// MARK: - MenuControllerDelegate

void Orchestrator::menuControllerDidSelectMenuItem(MenuItem menuItem) {
    switch (menuItem.type) {
        case MenuItemTypeRun:
            currentKeyHandler = pumpController;
            pumpController->run();
            break;

        case MenuItemTypeCalibrate:
            pumpCalibrator->calibrate();
            currentKeyHandler = pumpCalibrator;
            break;

        default:
            break;
    }
}

// MARK: - PumpControllerDelegate

void Orchestrator::pumpControllerDidPressMenu() {
    showMenu();
}

// MARK: - PumpCalibratorDelegate

void Orchestrator::pumpCalibratorDidFinishWithSpeedToMillilitersRatio(float ratio) {
    pumpController->applyCalibratedSpeedRatio(ratio);
    showMenu();
}

void Orchestrator::showMenu() {
    this->menuController->showMenu();
    this->currentKeyHandler = menuController;
}
