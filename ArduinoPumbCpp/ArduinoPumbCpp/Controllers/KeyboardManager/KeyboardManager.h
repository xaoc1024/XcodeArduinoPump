#ifndef KeyboardManager_h
#define KeyboardManager_h

#include "Arduino.h"
#include "LoopInterface.h"
#include "KeyPressable.h"

class KeyboardManagerDelegate {
public:
    virtual void keyboardManagerDidReadKey(KeyboardKey) = 0;
};

class KeyboardManager: public LoopInterface
{
public:
    KeyboardManager();

    // MAKR: - LoopInterface interface
    void loop();

    KeyboardManagerDelegate *delegate;

private:
    KeyboardKey readKey();
};

#endif /* KeyboardManager_h */
