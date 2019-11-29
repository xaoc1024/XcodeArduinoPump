#include "Processor.h"

Processor::Processor(PumpController *pumpController, KeyboardManager *keyboardManager, MenuController *menuController) {
    this->pumpController = pumpController;

    this->keyboardManager = keyboardManager;
    this->keyboardManager->delegate = this;

    this->menuController = menuController;
    this->menuController->delegate = this;

    this->menuController->showMenu();
    this->state = ProcessorStateMenu;

    this->currentKeyHandler = menuController;
}

// MAKR: - LoopInterface interface

void Processor::loop() {
    keyboardManager->loop();
}

// MAKR: - KeyboardManagerDelegate
void Processor::keyboardManagerDidReadKey(KeyboardKey theKey) {
    currentKeyHandler->pressKey(theKey);
//
//    switch (state) {
//        case ProcessorStateMenu:
//            menuController->pressKey(theKey);
//
//        case ProcessorStateRunning:
//
//        default:
//            break;
//    }
}

// MARK: - MenuControllerDelegate

void Processor::menuControllerDidSelectMenuItem(MenuItem menuItem) {
    switch (menuItem.type) {
        case MenuItemTypeRun:
            currentKeyHandler = pumpController;
//            pumpController->

        case MenuItemTypeCalibrate:
            setState(ProcessorStateCalibration);

        default:
            break;
    }
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
