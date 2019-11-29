#include "MenuController.h"

MenuController::MenuController(LiquidCrystal *lcd) {
    MenuItem defaultItem;
    menuItems[MenuItemTypeRun].title = "Default";
    menuItems[MenuItemTypeRun].type = MenuItemTypeRun;

    menuItems[MenuItemTypeCalibrate].title = "Calibration";
    menuItems[MenuItemTypeCalibrate].type = MenuItemTypeCalibrate;

    menuItems[MenuItemTypeRegime].title = "Regime";
    menuItems[MenuItemTypeRegime].type = MenuItemTypeRegime;

    isMenuShown = false;
    currentlyPresentedItem = MenuItemTypeRun;

    lcd = lcd;//LiquidCrystal(8, 9, 4, 5, 6, 7);
}

void MenuController::showMenu() {
    isMenuShown = true;
    showCurrentItem();
}

void MenuController::hideMenu() {
    isMenuShown = true;
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
