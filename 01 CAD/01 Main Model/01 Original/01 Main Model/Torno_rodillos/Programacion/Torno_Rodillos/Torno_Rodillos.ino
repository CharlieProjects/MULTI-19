//=================================================================================
// Script by: Juan Carlos Botero
// creation date: 11/12/2019
// version: development 1.0
// last update: 11/12/2019
//================================================================================

#include <Wire.h>
#include <LCD.h>
#include <AccelStepper.h> //http://www.airspayce.com/mikem/arduino/AccelStepper/index.html
#include <OneButton.h> //http://www.mathertel.de/Arduino/OneButtonLibrary.aspx
#include <Encoder.h> //https://github.com/ericbarch/arduino-libraries/blob/master/Encoder/Encoder.h
#include <LiquidCrystal_I2C.h> //https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library/blob/master/LiquidCrystal_I2C.h
#define ENCODER_DO_NOT_USE_INTERRUPTS

// STEPERS INITIALIZATION ===========================================================
AccelStepper stepper_X(1, 5, 2); // (I,S,D) I = steper driver interface S= STEP D= DIR
const int EN = 8;

const int SPR_X = 200; // X Stepps in one revolution

// DISPLAY INITIALIZATION ==========================================================
LiquidCrystal_I2C  lcd(0x3F, 2, 1, 0, 4, 5, 6, 7);

// ROTARY ENCODER INITIALIZATION ===================================================
float oldPosition  = 0;
float newPosition = 0;
int Encoder_pin_A = 13;
int Encoder_pin_B = 12;
int Encoder_clik_C = 9;
float increment = 10;
Encoder myEnc(Encoder_pin_A, Encoder_pin_B);
OneButton button0(Encoder_clik_C, true);

//Other variables ============================================================
unsigned long old_time = 0;
unsigned long new_time = 0;
int Sleep_time = 10000;
bool Mode = false;
bool flag = false;
int Vel = 50;
int Vel1 = 50;
int Vel2 = 250;
int RPMVel = 0;

void setup() {
  //SERIAL SET UP
  Serial.begin (9600);
  Serial.println("Start");
  // STEPPERS ===================================================================
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
  stepper_X.disableOutputs();
  stepper_X.setMaxSpeed(1000);
  stepper_X.setAcceleration(5000);
  //  stepper_X.setSpeed(10000);


  // DISPLAY ===================================================================
  lcd.begin (16, 2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();
  clearLine(0);
  lcd.setCursor (3, 0);
  lcd.print("TEHO");
  clearLine(1);
  lcd.setCursor (2, 1);
  lcd.print("Helli");
  delay(2000);
  clearLine(1);
  lcd.setCursor (2, 1);
  lcd.print("START");

  // ROTARY ENCODER ============================================================
  button0.attachClick(singleClick);
  button0.attachDoubleClick(doubleclick);

  //button0.attachDoubleClick(doubleClick);
  //button0.attachLongPressStart(longPressStart);
  //button0.attachDuringLongPress(longPress);
  //button0.attachLongPressStop(longPressStop);
  myEnc.write(newPosition * 4 * increment);

}

void loop() {

  button0.tick();
  MODE();
  //  Encoder_Check();
  //  sleep(0);
}

void MODE() {
  if (Mode == true) {
    //stepper_X.moveTo(1000);
    if (flag == true) {
      flag = false;
      Serial.println("one time");
      stepper_X.setSpeed(Vel);
      lcd.setCursor (2, 1);
      lcd.print("ON: ");
      RPMVel = PPS2RPM(Vel);
      lcd.print (RPMVel);
      lcd.print(" RPM");
    }
    stepper_X.runSpeed();
    //    stepper_X.run();

    //    lcd.print("  500 SPM  ");
  }
  else if (Mode == false) {

    lcd.setCursor (2, 1);
    lcd.print("OFF:");
    RPMVel = PPS2RPM(Vel);
    lcd.print (RPMVel);
    lcd.print(" RPM");
  }
}

void Encoder_Check() {
  newPosition = (myEnc.read() / 4) * increment;
  if (newPosition != oldPosition)
  {
    Serial.println(newPosition);
    lcd.setCursor (2, 1);
    lcd.print(newPosition);
    sleep(1);
    //RPM_X = newPosition;

    //    if (SetUpKey == true) {
    //      SetUpMenu( RPM_X, 0);
    //      float local = RPM2SPS(RPM_X);
    //      stepper_X.setSpeed(local);
    //    }
    oldPosition = newPosition;
  }
} // Encoder_Check

void singleClick() {
  sleep(1);
  Serial.println("singleClick");
  Mode = !Mode;
  flag = true;

} //singleClick

void doubleclick() {
  sleep(1);
  if (Vel == Vel1) {
    Vel = Vel2;
  }
  else if (Vel == Vel2) {
    Vel = Vel1;
  }
  Serial.println("singleClick");
  flag = true;

}// doubleclick


void sleep(int T)
{
  if (T == 1)
  {
    old_time = millis();
    lcd.setBacklight(HIGH);
  }
  unsigned long new_time = millis();

  if (new_time - old_time > Sleep_time)
  {
    lcd.setBacklight(LOW);
  }
}
void clearLine(int line) {
  lcd.setCursor (0, line);
  lcd.print("                ");
} // clearLine

int PPS2RPM(int pps) {
//  int RPM = pps * 1.8 * 60 / 360;
  int RPM = pps * 0.3;
  Serial.print(RPM);
  Serial.print(" RPM");
  return RPM;
}
