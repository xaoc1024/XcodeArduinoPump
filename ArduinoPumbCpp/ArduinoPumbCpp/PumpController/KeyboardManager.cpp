#include "KeyboardManager.h"

KeyboardManager::KeyboardManager() { }

void KeyboardManager::loop() {
    if (this->delegate != NULL) {
        KeyboardKey key = readKey();
        this->delegate->keyboardManagerDidReadKey(key);
    }
}

KeyboardKey KeyboardManager::readKey(){//1-719, 2 - 477, 3 - 131, 4 -305, 5 - 0
    delay(100);
    int val = analogRead(0);
    delay(100);
    if (val < 100) return KeyboardKeyRight;
    else if (val < 200) return KeyboardKeyUp;
    else if (val < 400) return KeyboardKeyDown;
    else if (val < 600) return KeyboardKeyLeft;
    else if (val < 800) return KeyboardKeySelect;

    return KeyboardKeyNone;
}
