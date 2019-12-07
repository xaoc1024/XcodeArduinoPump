#ifndef KeyboardManager_h
#define KeyboardManager_h

#include "Arduino.h"
#include "LoopInterface.h"
#include "KeyPressable.h"

class KeyboardManagerDelegate {
public:
    virtual void keyboardManagerDidReadKey(KeyboardKey) = 0;
};

struct KeyInProgress {
    KeyboardKey currentKey;
    unsigned long timestamp;
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
    KeyInProgress keyInProgress;
};

#endif /* KeyboardManager_h */
