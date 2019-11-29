#ifndef Processor_h
#define Processor_h

#include "Arduino.h"
#include "PumpController.h"
#include "KeyboardManager.h"
#include "LoopInterface.h"
#include "MenuController.h"


enum ProcessorState {
    ProcessorStateMenu = 0,
    ProcessorStateRunning,
    ProcessorStateCalibration
};

class Processor: public LoopInterface, KeyboardManagerDelegate, MenuControllerDelegate
{
public:
    Processor(PumpController*, KeyboardManager*, MenuController*);

    PumpController *pumpController;
    KeyboardManager *keyboardManager;
    MenuController *menuController;

    // MAKR: - LoopInterface interface
    void loop();

    // MAKR: - KeyboardManagerDelegate interface
    void keyboardManagerDidReadKey(KeyboardKey);

    // MARK: - MenuControllerDelegate
    void menuControllerDidSelectMenuItem(MenuItem);

private:
    KeyPressable *currentKeyHandler;
    ProcessorState state;
    void setState(ProcessorState state);
};

#endif /* Processor_h */
