/* ==============================================================================
 * Script by: Juan Carlos Botero 
 * Date: 08/08/2020
 * Version: 2.0.0
 * ==============================================================================
 *                      Copyright (c) 2020 Charlie Projects                      
 *                      github.com/CharlieProjects/MULTI-19                      
 * ==============================================================================
 * =========================  CONVEYOR MULTI-19 CONFIG  =========================
 * ========================   Multiplo Colombia S.A.S.  =========================
 * ==============================================================================
 *  MIT License
 *
 * Copyright (c) 2020 CHARLIE PROJECTS
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// =============== INCLUDE ====================
#include <Arduino.h>
#include <Display.h>

#include <Wire.h>
#include <EEPROM.h>
#include <SPI.h>

#include <OneButton.h>
#include <LoRa.h>
#include <ESP8266WiFi.h>

extern "C"
{
#include "user_interface.h"
}

// ================ INPUTS =====================
#define START           11
#define STOP            12
#define SwFWR           13
#define SwRWD           14
#define SwStop          15
#define SwUP            16
#define SwDOWN          17 
#define finalCarrera    18
#define SwBeacon        19
#define SwReflector     20 
#define Shunt           A0
#define Temp            A1
#define Hum             A2
#define GPS             23 
#define Sw1             24
#define Sw2             25
#define Sw3             26
#define Sw4             27
#define charger         28

// ================== OUTPUTS ==================
#define Beacon           1
#define Reflector        2 
#define UP               3
#define DOWN             4 
#define FWR              5
#define RWD              6
#define batTeryState1    7
#define batteryState2    8
#define generalState1    9
#define generalState2   10

// ============= OTHER VARIABLES ==============
#define STAND_BY         1
#define OPERATION        2
#define CHARGING         3
#define E_STOP           4
byte state = STAND_BY;

const long frequency = 915E6;  // LoRa Frequency
const int csPin = 10;          // LoRa radio chip select
const int resetPin = 9;        // LoRa radio reset
const int irqPin = 2;          // Must be a hardware interrupt pin


// =============== SETTINGS ===================
OneButton button1(SwStop, true);

void click(){}
void doubleclick(){}
void longPressStart(){}
void longPressStop(){}
void longPress(){}

void OneButtonini(){
  button1.attachClick(click);
  button1.attachDoubleClick(doubleclick);
  button1.attachLongPressStart(longPressStart);
  button1.attachLongPressStop(longPressStop);
  button1.attachDuringLongPress(longPress);
}
