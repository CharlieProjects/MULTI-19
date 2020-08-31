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

// =============== INCLUDE ======================================================
#include <Arduino.h>
// #include <Display.h>

#include <EEPROM.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
 
#include <RTClib.h>
// #include <OneButton.h>
// #include <LoRa.h>
// #include <ESP8266WiFi.h>
#include <GoldenMotor.h>

// extern "C"
// {
// #include "user_interface.h"
// }

// =============== CODE VERSION =================================================
#define version '2.0.0'
char update[]= "09-08-2020";
char ID[]= "XXXX001MULTI19";

// ================ INPUTS ======================================================
#define START           36 // START selector,  (Must be a hardware interrupt pin)
#define STOP            37 // STOP button,     (Must be a hardware interrupt pin)
#define SwFWR           35 // Forward switch input pin 
#define SwRWD           32 // Rewind switch input pin
#define SwStop          39 // Band stop switch input pin 
#define SwUP            33 // Up switch input pin
#define SwDOWN          25 // Down switch input pin
#define SwLimit          0 // Limit end switch input pin
#define SwBeacon         0 // Beacon light switch input pin
#define SwReflector      0 // Reflector light switch input pin
#define shunt            0 // Shunt sensor input pin
#define temp             0 // Temp sensor input pin
#define hum              0 // Hum sensor input pin
#define GPS              0 // GPS module signal input pin
#define Sw1              0 // Aux switch input pin
#define Sw2              0 // Aux switch input pin
#define Sw3              0 // Aux switch input pin
#define Sw4              0 // Aux switch input pin
#define charger          0 // Charger input pin (Must be a hardware interrupt pin)

// ================== OUTPUTS ===================================================
#define Beacon           0 // Beacon light output pin
#define Reflector        0 // Reflector light output pin
#define UP               0 // Up output pin
#define DOWN            15 // Down output pin
#define FWR              0 // Forward output pin
#define RWD              0 // Rewind output pin
#define bandPWM          0 // band speed output pin 
#define batteryState1    0 // Battery indicator color 1 output pin 
#define batteryState2    2 // Battery indicator color 2 output pin
#define generalState1    0 // General state color 1 output pin
#define generalState2    0 // General state color 2 output pin

// ================== STATES ====================================================
#define STAND_BY         0 // main FSM state 1
#define OPERATION        1 // main FSM state 2
#define CHARGING         2 // main FSM state 3
#define E_STOP           3 // main FSM state 4
byte state = STAND_BY;
byte oldstate =         -1;

byte elevationState =    0;
byte brakesState =       0;

// ============= OTHER VARIABLES ================================================
const long frequency = 915E6;  // LoRa Frequency
const int csPin =       10;    // LoRa radio chip select
const int resetPin =     9;    // LoRa radio reset
const int irqPin =       2;    // (Must be a hardware interrupt pin)

uintmax_t oldMillis =    0;
const int blinkInterval = 500;

// =============== SETTINGS =====================================================
byte DIGITAL_INPUTS[] = {START, STOP, SwFWR, SwRWD, SwStop, SwUP, SwDOWN, SwLimit, SwBeacon, SwReflector, Sw1, Sw2, Sw3, Sw4, charger}; //
byte DIGITAL_OUTPUTS[] = {Beacon, Reflector, UP, DOWN, FWR, RWD, batteryState1, batteryState2, generalState1, generalState2};//
// OneButton button1(SwStop, true);
