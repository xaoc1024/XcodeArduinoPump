#ifndef Processor_h
#define Processor_h

#include "Arduino.h"
#include "PumpController.h"
#include "KeyboardManager.h"
#include "LoopInterface.h"

class Processor: public LoopInterface, KeyboardManagerDelegate
{
public:
    Processor(PumpController *pumpController, KeyboardManager *keyboardManager);

    PumpController *controller = NULL;
    KeyboardManager *keyboardManager = NULL;

    // MAKR: - LoopInterface interface
    void loop();

    // MAKR: - KeyboardManagerDelegate interface
    void keyaboardManagerDidReadTheKey(KeyboardKey);
};

#endif /* Processor_h */
