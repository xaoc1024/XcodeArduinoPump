//
//  KeyboardManager.h
//  ArduinoPumpCpp
//
//  Created by Andriy Zhuk on 11/3/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#ifndef KeyboardManager_h
#define KeyboardManager_h

#include "Arduino.h"
#include "LoopInterface.h"

enum KeyboardKey {
    KeyboardKeySelect,
    KeyboardKeyUp,
    KeyboardKeyDown,
    KeyboardKeyLeft,
    KeyboardKeyRight,
    KeyboardKeyNone
};

class KeyboardManagerDelegate {
public:
    virtual void keyaboardManagerDidReadTheKey(KeyboardKey) = 0;
};

class KeyboardManager: public LoopInterface
{
public:
    KeyboardManager();

    // MAKR: - LoopInterface interface
    void tick();

    KeyboardManagerDelegate *delegate;

private:
    KeyboardKey readKey();
};

#endif /* KeyboardManager_h */
