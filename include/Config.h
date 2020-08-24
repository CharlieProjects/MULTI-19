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
#include <Display.h>

#include <EEPROM.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
 
// #include <RTClib.h>
#include <OneButton.h>
#include <LoRa.h>
#include <ESP8266WiFi.h>

extern "C"
{
#include "user_interface.h"
}

// =============== CODE VERSION =================================================
#define version "2.0.0"
#define update "09-08-2020"
#define ID "XXXX001MULTI19"

// ================ INPUTS ======================================================
#define START           11 // START selector,  (Must be a hardware interrupt pin)
#define STOP            12 // STOP button,     (Must be a hardware interrupt pin)
#define SwFWR           13 // Forward switch input pin 
#define SwRWD           14 // Rewind switch input pin
#define SwStop          15 // Band stop switch input pin 
#define SwUP            16 // Up switch input pin
#define SwDOWN          17 // Down switch input pin
#define SwLimit         18 // Limit end switch input pin
#define SwBeacon        19 // Beacon light switch input pin
#define SwReflector     20 // Reflector light switch input pin
#define shunt           A0 // Shunt sensor input pin
#define temp            A1 // Temp sensor input pin
#define hum             A2 // Hum sensor input pin
#define GPS             23 // GPS module signal input pin
#define Sw1             24 // Aux switch input pin
#define Sw2             25 // Aux switch input pin
#define Sw3             26 // Aux switch input pin
#define Sw4             27 // Aux switch input pin
#define charger         28 // Charger input pin (Must be a hardware interrupt pin)

// ================== OUTPUTS ===================================================
#define Beacon           1 // Beacon light output pin
#define Reflector        2 // Reflector light output pin
#define UP               3 // Up output pin
#define DOWN             4 // Down output pin
#define FWR              5 // Forward output pin
#define RWD              6 // Rewind output pin
#define bandPWM          7 // band speed output pin 
#define batTeryState1    7 // Battery indicator color 1 output pin 
#define batteryState2    8 // Battery indicator color 2 output pin
#define generalState1    9 // General state color 1 output pin
#define generalState2   10 // General state color 2 output pin

// ================== STATES ====================================================
#define STAND_BY         0x00  // main FSM state 1
#define OPERATION        0x01  // main FSM state 2
#define CHARGING         0x02  // main FSM state 3
#define E_STOP           0x03  // main FSM state 4
byte state = STAND_BY;

// ============= OTHER VARIABLES ================================================
const long frequency = 915E6;  // LoRa Frequency
const int csPin = 10;          // LoRa radio chip select
const int resetPin = 9;        // LoRa radio reset
const int irqPin = 2;          // (Must be a hardware interrupt pin)

// =============== SETTINGS =====================================================
byte DIGITAL_INPUTS []={START, STOP, SwFWR, SwRWD, SwUP, SwDOWN, SwLimit, SwBeacon, SwReflector, Sw1, Sw2, Sw3, Sw4, charger};
byte DIGITAL_OUTPUTS[]={Beacon, Reflector, UP, DOWN, FWR, RWD, batTeryState1, batteryState2, generalState1, generalState2};
OneButton button1(SwStop, true);
