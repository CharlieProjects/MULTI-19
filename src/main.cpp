/* ==============================================================================
 * Script by: Juan Carlos Botero 
 * Date: 08/08/2020
 * Version: 2.0.0
 * ==============================================================================
 *                      Copyright (c) 2020 Charlie Projects                      
 *                      github.com/CharlieProjects/MULTI-19                      
 * ==============================================================================
 * ========================      CONVEYOR MULTI-19      =========================
 * ========================   Multiplo Colombia S.A.S.  =========================
 * ==============================================================================
 * 
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

#include <Conveyor.h>


void  setup()
{
  display.init();
  displayStart();

  Serial.begin(115200);
  Serial.println();
  Serial.println("...Set Up...");

  OneButtonini();
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