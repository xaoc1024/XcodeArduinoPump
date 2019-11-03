//
//  EngineController.cpp
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/27/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#include "EngineController.h"

static byte dirPin = 12;
static byte stepPin = 13;
static byte enPin = 11;

EngineController::EngineController() {
    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
    pinMode(enPin, OUTPUT);
    digitalWrite(dirPin, HIGH);
    digitalWrite(enPin, HIGH);
}

void EngineController::stopEngine() {
    noTone(stepPin);
}

void EngineController::startEngine(int speed) {
    tone(stepPin, speed);
}
