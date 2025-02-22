/**
 * SetKD.cpp
 */
#include "SetKD.h"

#include "Devices/LiquidCrystal_TC.h"
#include "Devices/PID_TC.h"

void SetKD::setValue(float value) {
  PID_TC::instance()->setKd(value);

  char output[17];
  snprintf_P(output, sizeof(output), (PGM_P)F("New KD=%.1f"), value);
  LiquidCrystal_TC::instance()->writeLine(output, 1);
  returnToMainMenu(3000);
}
