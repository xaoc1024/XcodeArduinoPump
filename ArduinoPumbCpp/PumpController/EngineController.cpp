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

void EngineController::startEngine(unsigned int speed, unsigned long time) {
    tone(stepPin, speed, time);
}
