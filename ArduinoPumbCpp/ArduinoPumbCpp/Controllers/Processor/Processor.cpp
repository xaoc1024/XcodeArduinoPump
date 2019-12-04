#include "Processor.h"

Processor::Processor(PumpController *pumpController, KeyboardManager *keyboardManager, MenuController *menuController) {
    this->pumpController = pumpController;
    this->pumpController->delegate = this;

    this->keyboardManager = keyboardManager;
    this->keyboardManager->delegate = this;

    this->menuController = menuController;
    this->menuController->delegate = this;
    this->menuController->showMenu();
    this->currentKeyHandler = menuController;
}

// MAKR: - LoopInterface interface

void Processor::loop() {
    keyboardManager->loop();
}

// MAKR: - KeyboardManagerDelegate
void Processor::keyboardManagerDidReadKey(KeyboardKey theKey) {
    currentKeyHandler->pressKey(theKey);
}

// MARK: - MenuControllerDelegate

void Processor::menuControllerDidSelectMenuItem(MenuItem menuItem) {
    switch (menuItem.type) {
        case MenuItemTypeRun:
            currentKeyHandler = pumpController;
            pumpController->run();

        case MenuItemTypeCalibrate:


        default:
            break;
    }
}

// MARK: - PumpControllerDelegate

void Processor::pumpControllerDidPressMenu() {
    this->menuController->showMenu();
    this->currentKeyHandler = menuController;
}

void Processor::setState(ProcessorState newState) {
    if (newState == state) {
        return;
    }

    state = newState;

    switch (newState) {
        case ProcessorStateMenu:
            break;

        case ProcessorStateRunning:
            break;

        case ProcessorStateCalibration:
            break;

        default:
            break;
    }
}
