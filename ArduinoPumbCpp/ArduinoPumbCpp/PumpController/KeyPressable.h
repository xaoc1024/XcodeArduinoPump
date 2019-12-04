#ifndef KeyPressable_h
#define KeyPressable_h

enum KeyboardKey {
    KeyboardKeySelect,
    KeyboardKeyUp,
    KeyboardKeyDown,
    KeyboardKeyLeft,
    KeyboardKeyRight,
    KeyboardKeyNone
};


class KeyPressable
{
public:
    virtual void pressKey(KeyboardKey) = 0;
};

#endif /* KeyPressable_h */
