#ifndef Orchestrator_h
#define Orchestrator_h

#include "Arduino.h"
#include "PumpController.h"
#include "KeyboardManager.h"
#include "LoopInterface.h"
#include "MenuController.h"
#include "PumpCalibrator.h"

class Orchestrator: public LoopInterface, KeyboardManagerDelegate, MenuControllerDelegate, PumpControllerDelegate, PumpCalibratorDelegate
{
public:
    Orchestrator(PumpController*, KeyboardManager*, MenuController*, PumpCalibrator*);

    PumpController *pumpController;
    KeyboardManager *keyboardManager;
    MenuController *menuController;
    PumpCalibrator *pumpCalibrator;

    // MAKR: - LoopInterface interface
    void loop();

    // MAKR: - KeyboardManagerDelegate interface
    void keyboardManagerDidReadKey(KeyboardKey);

    // MARK: - MenuControllerDelegate
    void menuControllerDidSelectMenuItem(MenuItem);

    // MARK: - PumpControllerDelegate
    void pumpControllerDidPressMenu();

    // MARK: - PumpCalibratorDelegate
    void pumpCalibratorDidFinishWithSpeedToMillilitersRatio(float);

private:
    KeyPressable *currentKeyHandler;
    void showMenu();
};

#endif /* Orchestrator_h */
