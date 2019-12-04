#ifndef MenuController_h
#define MenuController_h

#include "Arduino.h"
#include "KeyboardManager.h"
#include "LiquidCrystal.h"
#include "KeyPressable.h"

enum MenuItemType {
    MenuItemTypeRun = 0,
    MenuItemTypeCalibrate,
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

class MenuController: public KeyPressable {
public:
    MenuController(LiquidCrystal*);
    MenuControllerDelegate *delegate;

    void showMenu();
    void hideMenu();

    // MARK: - KeyPressable
    void pressKey(KeyboardKey);
    
private:
    bool isMenuShown;
    MenuItemType currentlyPresentedItem;
    MenuItem menuItems[MenuItemTypeCount];
    LiquidCrystal *lcd;

    void showCurrentItem();
    
};

#endif /* MenuController_h */
