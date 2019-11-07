//
//  Processor.cpp
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/28/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#include "Processor.h"

Processor::Processor(PumpController *pumpController, KeyboardManager *keyboardManager) {
    this->controller = pumpController;
    this->keyboardManager = keyboardManager;
    this->keyboardManager->delegate = this;
}

// MAKR: - LoopInterface interface

void Processor::tick() {
    keyboardManager->tick();
}

// MAKR: - KeyboardManagerDelegate

void Processor::keyaboardManagerDidReadTheKey(KeyboardKey) {
    
}
