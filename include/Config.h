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

// ================ INPUTS ======================================================
#define START           11 // Must be a hardware interrupt pin
#define STOP            12 // Must be a hardware interrupt pin
#define SwFWR           13 // Forward switch
#define SwRWD           14 // Rewind switch
#define SwStop          15 // Band stop switch
#define SwUP            16 // Up switch
#define SwDOWN          17 // Down switch
#define SwLimit         18 // Limit end switch
#define SwBeacon        19 // Beacon light switch   
#define SwReflector     20 // Reflector light switch
#define Shunt           A0 // Shunt sensor 
#define Temp            A1 // Temp sensor
#define Hum             A2 // Hum sensor 
#define GPS             23 // GPS module signal
#define Sw1             24 // Aux switch
#define Sw2             25 // Aux switch
#define Sw3             26 // Aux switch
#define Sw4             27 // Aux switch
#define charger         28 // Must be a hardware interrupt pin

// ================== OUTPUTS ===================================================
#define Beacon           1 // Beacon light
#define Reflector        2 // Reflector light
#define UP               3 // Up 
#define DOWN             4 // Down
#define FWR              5 // Forward
#define RWD              6 // Rewind
#define batTeryState1    7 // Battery indicator color 1
#define batteryState2    8 // Battery indicator color 2
#define generalState1    9 // General state color 1
#define generalState2   10 // General state color 2

// ============= OTHER VARIABLES ================================================
#define STAND_BY         1  // main FSM state 1
#define OPERATION        2  // main FSM state 2
#define CHARGING         3  // main FSM state 3
#define E_STOP           4  // main FSM state 4
byte state = STAND_BY;

const long frequency = 915E6;  // LoRa Frequency
const int csPin = 10;          // LoRa radio chip select
const int resetPin = 9;        // LoRa radio reset
const int irqPin = 2;          // Must be a hardware interrupt pin

// =============== SETTINGS =====================================================
OneButton button1(SwStop, true);
