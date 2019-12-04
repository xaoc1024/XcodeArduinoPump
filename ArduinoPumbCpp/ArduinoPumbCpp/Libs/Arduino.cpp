//
//  Arduino.c
//  ArduinoPumbCpp
//
//  Created by Andriy Zhuk on 10/27/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#include <stdio.h>
#include "Arduino.h"

void init() {}

void initVariant() {}

void pinMode(uint8_t left, uint8_t rigth) {}

void digitalWrite(uint8_t left, uint8_t right) {}

int digitalRead(uint8_t var) { return 0; }

int analogRead(uint8_t var) { return 0; }

void analogReference(uint8_t mode) {}

void analogWrite(uint8_t left, int right) {}

unsigned long millis() { return 0; }

unsigned long micros() { return 0; }

void delay(unsigned long var) {}

void delayMicroseconds(unsigned int us) {}

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout) { return 0; }
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout) { return 0; }

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) {}
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) { return 0; }

//void attachInterrupt(uint8_t one, void(*)(void)func, int mode) {}

void detachInterrupt(uint8_t one) {}

void setup() {}
void loop() {}

void tone(int one, int two) {}
void tone(uint8_t _pin, unsigned int frequency, unsigned long duration) {}
void noTone(int one) {}
