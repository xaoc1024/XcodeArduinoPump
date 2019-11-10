#include "Processor.h"

Processor::Processor(PumpController *pumpController, KeyboardManager *keyboardManager, MenuController *menuController) {
    this->controller = pumpController;

    this->keyboardManager = keyboardManager;
    this->keyboardManager->delegate = this;

    this->menuController = menuController;
    this->menuController->delegate = this;
}

// MAKR: - LoopInterface interface

void Processor::loop() {
    keyboardManager->loop();
}

// MAKR: - KeyboardManagerDelegate

void Processor::keyboardManagerDidReadKey(KeyboardKey) {

}

// MARK: - MenuControllerDelegate

void Processor::menuControllerDidSelectMenuItem(MenuItem) {

}
