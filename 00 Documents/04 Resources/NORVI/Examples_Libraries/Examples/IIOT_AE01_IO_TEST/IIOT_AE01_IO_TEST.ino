
/*

* Hardware : NORVI IIOT-AE01-R / IIOT-AE01-T

 *

 * Go to File \ Preferences

* - Add Additional Boards Manager URLs: https://dl.expressif.com/dl/package_esp32_index.json (can use commas, if more than one)

*

 * Boards Manager:

* Go to Tools \ Boards \ Boards Manager and add to the search field esp32

* select 'esp by espressif systems v1.0.4'

*

 * Boards:

 * Select 'ESP32 Dev Module'

*

 * include library:

 * 1. go to arduino IDE select 'Sketch \ Include Library \ Add *.ZIP library

* 2. add the ..\libraries\esp8266-oled-ssd1306.zip file

 *    (src: https://github.com/ThingPulse/esp8266-oled-ssd1306)  or

 *    (src: https://github.com/adafruit/Adafruit_SSD1306)

 *    EDIT I2C connections of wire library Wire.begin() to Wire.begin(16,17)
 
*/


#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`


SSD1306  display(0x3C, 16, 17);

#define ANALOG_PIN_0 36
int analog_value = 0;

int readLightSensor(){
  analog_value = analogRead(ANALOG_PIN_0);
  return analog_value                                                                                                ; //Read analog
}

unsigned int keyval=0;
String adcString;

// ================================================ SETUP ================================================
void setup() {
  
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  
  display.drawString(0, 0, "Hello Data");
  display.display();
  delay(300);

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  
  pinMode(2, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);

  pinMode(18, INPUT);
  pinMode(39, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(19, INPUT);
  pinMode(21, INPUT);
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(36, INPUT);

  adcAttachPin(36);

  
}




void loop() {

  
  digitalWrite(14, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
  update_display();
  
  delay(300);

  digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
  update_display();
  
    delay(300);

  digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
  update_display();
  
    delay(300);

  digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
    update_display();

    delay(300);

  digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
    update_display();

    delay(300);

  digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
    update_display();

    delay(300);

  digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
    update_display();

    delay(300);

  digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, HIGH);   // turn the LED on (HIGH is the voltage level)
    update_display();

  delay(300);

  digitalWrite(14, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, HIGH);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, HIGH);   // turn the LED on (HIGH is the voltage level)
    update_display();

    delay(300);

  digitalWrite(14, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(15, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(33, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(26, LOW);    // turn the LED on (HIGH is the voltage level)
  digitalWrite(27, LOW);   // turn the LED on (HIGH is the voltage level)
    update_display();

   delay(300);
  
  

}

void update_display(){
    display.clear();
  adcString = String(readLightSensor());
  display.drawString(0, 0, adcString);
  adcString = String(digitalRead(18));
  display.drawString(10, 15, adcString);
  adcString = String(digitalRead(39));
  display.drawString(25, 15, adcString);
  adcString = String(digitalRead(34));
  display.drawString(40, 15, adcString);
  adcString = String(digitalRead(35));
  display.drawString(55, 15, adcString);
  adcString = String(digitalRead(19));
  display.drawString(70, 15, adcString);
  adcString = String(digitalRead(21));
  display.drawString(85, 15, adcString);
  adcString = String(digitalRead(22));
  display.drawString(100, 15, adcString);
  adcString = String(digitalRead(23));
  display.drawString(115, 15, adcString);

  
  display.drawString(5, 30, "i0");
  display.drawString(25, 30, "i1");
  display.drawString(40, 30, "i2");
  display.drawString(55, 30, "i3");
  display.drawString(70, 30, "i4");
  display.drawString(85, 30, "i5");
  display.drawString(100, 30, "i6");
  display.drawString(115, 30, "i7");
  display.display();
}
