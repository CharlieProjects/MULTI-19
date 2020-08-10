/* ==============================================================================
 * Script by: Juan Carlos Botero 
 * Date: 08/08/2020
 * Version: 2.0.0
 * ==============================================================================
 *                      Copyright (c) 2020 Charlie Projects                      
 *                      github.com/CharlieProjects/MULTI-19                      
 * ==============================================================================
 * ======================== CONVEYOR MULTI-19 RESOURCES =========================
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

#include <Config.h>

// ================================= FUNCIONES ==================================
void conveyor() {}
void batteryCheck() {}
void breaks() {}
void elevation() {}
void illumination(byte L1, byte L2, byte S1, byte S2)
{
  digitalWrite(L1, digitalRead(S1));
  digitalWrite(L2, digitalRead(S2));
}

void dataLog() {}

void click() {}
void doubleclick() {}
void longPressStart() {}
void longPressStop() {}
void longPress() {}

void OneButtonBegin()
{
  button1.attachClick(click);
  button1.attachDoubleClick(doubleclick);
  button1.attachLongPressStart(longPressStart);
  button1.attachLongPressStop(longPressStop);
  button1.attachDuringLongPress(longPress);
}

void ConveyorBegin()
{
  for (byte i = 0; i < sizeof(DIGITAL_INPUTS); i++)
  {
    pinMode(DIGITAL_INPUTS[i], INPUT);
  }
  for (byte i = 0; i < sizeof(DIGITAL_OUTPUTS); i++)
  {
    pinMode(DIGITAL_OUTPUTS[i], OUTPUT);
    digitalWrite(DIGITAL_OUTPUTS[i], LOW);
  }
  OneButtonBegin();
}