#ifndef Processor_h
#define Processor_h

#include "Arduino.h"
#include "PumpController.h"
#include "KeyboardManager.h"
#include "LoopInterface.h"
#include "MenuController.h"

class Processor: public LoopInterface, KeyboardManagerDelegate, MenuControllerDelegate
{
public:
    Processor(PumpController*, KeyboardManager*, MenuController*);

    PumpController *controller;
    KeyboardManager *keyboardManager;
    MenuController *menuController;

    // MAKR: - LoopInterface interface
    void loop();

    // MAKR: - KeyboardManagerDelegate interface
    void keyboardManagerDidReadKey(KeyboardKey);

    // MARK: - MenuControllerDelegate
    void menuControllerDidSelectMenuItem(MenuItem);
};

#endif /* Processor_h */
