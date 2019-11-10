#include "MenuController.h"

MenuController::MenuController(LiquidCrystal *lcd) {
    MenuItem defaultItem;
    menuItems[MenuItemTypeDefault].title = "Default";
    menuItems[MenuItemTypeDefault].type = MenuItemTypeDefault;

    menuItems[MenuItemTypeCalibration].title = "Calibration";
    menuItems[MenuItemTypeCalibration].type = MenuItemTypeCalibration;

    menuItems[MenuItemTypeRegime].title = "Regime";
    menuItems[MenuItemTypeRegime].type = MenuItemTypeRegime;

    isMenuOnShown = false;
    currentlyPresentedItem = MenuItemTypeDefault;

    lcd = lcd;//LiquidCrystal(8, 9, 4, 5, 6, 7);
}

void MenuController::showMenu() {
    isMenuOnShown = true;
    showCurrentItem();
}

void MenuController::hideMenu() {
    isMenuOnShown = true;
    lcd->clear();
}

void MenuController::pressKey(KeyboardKey key) {
    switch (key) {
        case KeyboardKeyLeft: {
            if (currentlyPresentedItem > 0) {
                currentlyPresentedItem = (MenuItemType)((int)currentlyPresentedItem - 1);
                showCurrentItem();
            }
            break;
        }

        case KeyboardKeyRight: {
            if (currentlyPresentedItem < MenuItemTypeCount - 1) {
                currentlyPresentedItem = (MenuItemType)((int)currentlyPresentedItem + 1);
                showCurrentItem();
            }
            break;
        }

        case KeyboardKeySelect: {
            if (delegate != NULL) {
                delegate->menuControllerDidSelectMenuItem(menuItems[currentlyPresentedItem]);
            }
            break;
        }


        default: break;
    }
}

void MenuController::showCurrentItem() {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print(menuItems[currentlyPresentedItem].title);
}
