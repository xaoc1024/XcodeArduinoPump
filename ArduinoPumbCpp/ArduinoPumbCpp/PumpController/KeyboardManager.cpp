#include "KeyboardManager.h"

/// Time (in milliseconds) the key is needed to be pressed in order to be recognized. If key is pressed for less period of time, than thisthreshold, it won't be recognized. If key if pressed for longer period of time, if will be recognized x times, where x = floor(time / threshold)
static unsigned int kKeyRecognitionThresholdMs = 200; // 100 ms;

static KeyInProgress kKeyInProgressNone = {
    .currentKey = KeyboardKeyNone,
    .timestamp = 0
};

KeyboardManager::KeyboardManager() {
    this->keyInProgress = kKeyInProgressNone;
}

void KeyboardManager::loop() {
    KeyboardKey key = readKey();

    if (key == KeyboardKeyNone) {
        keyInProgress.currentKey = KeyboardKeyNone;
        return;
    }

    if (keyInProgress.currentKey != key) {
        keyInProgress.currentKey = key;
        keyInProgress.timestamp = millis();
    }
    else if ((millis() - keyInProgress.timestamp) >= kKeyRecognitionThresholdMs) {
        this->delegate->keyboardManagerDidReadKey(keyInProgress.currentKey);
        keyInProgress = kKeyInProgressNone;
    }
}

KeyboardKey KeyboardManager::readKey(){//1-719, 2 - 477, 3 - 131, 4 -305, 5 - 0
    int val = analogRead(0);
    if (val < 100) return KeyboardKeyRight;
    else if (val < 200) return KeyboardKeyUp;
    else if (val < 400) return KeyboardKeyDown;
    else if (val < 600) return KeyboardKeyLeft;
    else if (val < 800) return KeyboardKeySelect;

    return KeyboardKeyNone;
}
