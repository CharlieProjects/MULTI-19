// ============================================
// Script by: Juan Carlos Botero 
// Date: 08/08/2020
// Version: 2.0.0
// ============================================
//      Copyright (c) 2020 Charlie Projects
//      github.com/CharlieProjects/MULTI-19
// ============================================
// ========     CONVEYOR MULTI-19      ========
// ========  Multiplo Colombia S.A.S.  ========
// ============================================

#include <Arduino.h>
#include <Config.h>
#include <Conveyor.h>
#include <Display.h>

#include <ESP8266WiFi.h>
#include <Wire.h>
#include <EEPROM.h>

extern "C"
{
#include "user_interface.h"
}

#define STAND_BY  1
#define OPERATION 2
#define CHARGING  3
#define E_STOP    4
byte state = STAND_BY;

void setup()
{
  /* start Display */
  display.init();
  displayStart();

  /* start Serial */
  Serial.begin(115200);
  Serial.println();
  Serial.println("...Set Up...");
}

void loop()
{
  switch (state)
  {
  case STAND_BY:

    state = digitalRead(START) ? OPERATION : STAND_BY;
    break;
  case OPERATION:
    conveyor(true, 10);
    elevation();
    breaks();
    batteryCheck();
    illumination(Beacon, Reflector, SwBeacon, SwReflector);

    state = digitalRead(STOP) ? E_STOP : !digitalRead(START) ? STAND_BY : OPERATION;
    break;
  case CHARGING:
    batteryCheck();

    state = !digitalRead(charger) ? STAND_BY : CHARGING;
    break;
  case E_STOP:
    digitalWrite(FWR, LOW);
    digitalWrite(RWD, LOW);
    digitalWrite(UP, LOW);
    digitalWrite(DOWN, LOW);

    state = !(digitalRead(START) && digitalRead(STOP)) ? STAND_BY : E_STOP;
    break;
  }
}