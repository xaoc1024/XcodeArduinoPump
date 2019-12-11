#include "Orchestrator.h"

I2CMemoryManager manager = I2CMemoryManager(0x50);
EngineController engine = EngineController();
LiquidCrystal lcd = LiquidCrystal(8, 9, 4, 5, 6, 7);

Orchestrator *orchestrator;

void setup() {  
  PumpController pumpController = PumpController(&engine, &manager, &lcd);
  KeyboardManager keyboardManager = KeyboardManager();
  MenuController menuController = MenuController(&lcd);
  PumpCalibrator pumpCalibrator = PumpCalibrator(&engine, &lcd);

  Orchestrator localOrchestrator = Orchestrator(&pumpController, &keyboardManager, &menuController, &pumpCalibrator);
  orchestrator = &localOrchestrator;
}

void loop() {
  orchestrator->loop();
}
