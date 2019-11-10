#ifndef MenuController_h
#define MenuController_h

#include "Arduino.h"
#include "KeyboardManager.h"
#include "LiquidCrystal.h"

enum MenuItemType {
    MenuItemTypeDefault = 0,
    MenuItemTypeCalibration,
    MenuItemTypeRegime,
    MenuItemTypeCount
};

struct MenuItem {
    MenuItemType type;
    String title;
};

class MenuControllerDelegate {
public:
    virtual void menuControllerDidSelectMenuItem(MenuItem) = 0;
};


class MenuController {
public:
    MenuController(LiquidCrystal*);
    MenuControllerDelegate *delegate;

    void showMenu();
    void hideMenu();
    void pressKey(KeyboardKey);
    
private:
    bool isMenuOnShown;
    MenuItemType currentlyPresentedItem;
    MenuItem menuItems[MenuItemTypeCount];
    LiquidCrystal *lcd;

    void showCurrentItem();
    
};

#endif /* MenuController_h */
