#include "LiquidCrystal.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

// When the display powers up, it is configured as follows:
//
// 1. Display clear
// 2. Function set: 
//    DL = 1; 8-bit interface data 
//    N = 0; 1-line display 
//    F = 0; 5x8 dot character font 
// 3. Display on/off control: 
//    D = 0; Display off 
//    C = 0; Cursor off 
//    B = 0; Blinking off 
// 4. Entry mode set: 
//    I/D = 1; Increment by 1 
//    S = 0; No shift 
//
// Note, however, that resetting the Arduino doesn't reset the LCD, so we
// can't assume that its in that state when a sketch starts (and the
// LiquidCrystal constructor is called).

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  init(0, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
  init(0, rs, 255, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

LiquidCrystal::LiquidCrystal(uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
{
  init(1, rs, rw, enable, d0, d1, d2, d3, 0, 0, 0, 0);
}

LiquidCrystal::LiquidCrystal(uint8_t rs,  uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3){}

void LiquidCrystal::init(uint8_t fourbitmode, uint8_t rs, uint8_t rw, uint8_t enable,
			 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			 uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7){}

void LiquidCrystal::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) {}

void LiquidCrystal::setRowOffsets(int row0, int row1, int row2, int row3){}

/********** high level commands, for the user! */
void LiquidCrystal::clear()
{}

void LiquidCrystal::home()
{
}

void LiquidCrystal::setCursor(uint8_t col, uint8_t row)
{
}

// Turn the display on/off (quickly)
void LiquidCrystal::noDisplay() {
}

// Turns the underline cursor on/off
void LiquidCrystal::noCursor() {
}
void LiquidCrystal::cursor() {
}

// Turn on and off the blinking cursor
void LiquidCrystal::noBlink() {
}
void LiquidCrystal::blink() {
}

// These commands scroll the display without changing the RAM
void LiquidCrystal::scrollDisplayLeft(void) {
}
void LiquidCrystal::scrollDisplayRight(void) {
}

// This is for text that flows Left to Right
void LiquidCrystal::leftToRight(void) {
}

// This is for text that flows Right to Left
void LiquidCrystal::rightToLeft(void) {
}

// This will 'right justify' text from the cursor
void LiquidCrystal::autoscroll(void) {
}

// This will 'left justify' text from the cursor
void LiquidCrystal::noAutoscroll(void) {
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void LiquidCrystal::createChar(uint8_t location, uint8_t charmap[]) {
}

void LiquidCrystal::print(const String & str) { }
void LiquidCrystal::print(const int & value) { }

/*********** mid level commands, for sending data/cmds */

//inline void LiquidCrystal::command(uint8_t value) {
//}
//
//inline size_t LiquidCrystal::write(uint8_t value) {
//    return 1;
//}
//
///************ low level data pushing commands **********/
//
//// write either command or data, with automatic 4/8-bit selection
//void LiquidCrystal::send(uint8_t value, uint8_t mode) {
//}
//
//void LiquidCrystal::pulseEnable(void) {
//}
//
//void LiquidCrystal::write4bits(uint8_t value) {
//}
//
//void LiquidCrystal::write8bits(uint8_t value) {
//}
