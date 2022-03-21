
/*

* Hardware : NORVI IIOT-AE02-V / IIOT-AE02-I

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

* 3. add the ..\libraries\Adafruit_ADS1X15-master.zip file

 *    (src: https://github.com/adafruit/Adafruit_ADS1X15  or

 *    EDIT I2C connections of wire library Wire.begin() to Wire.begin(16,17)
 
*/


#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
#include <Adafruit_ADS1015.h>


SSD1306  display(0x3C, 16, 17);
Adafruit_ADS1115 ads2(0x48);  /* Use this for the 16-bit version */
Adafruit_ADS1115 ads1(0x49);



int reading[8]={0};
String adcString[8];


#define ANALOG_PIN_0 36
int analog_value = 0;

int readSwitch(){
  analog_value = analogRead(ANALOG_PIN_0);
  return analog_value                                                                                                ; //Read analog
}

unsigned int keyval=0;
String buttonString;

// ================================================ SETUP ================================================
void setup() {

  Serial.begin(9600);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  
  display.drawString(0, 0, "Hello World");
  display.display();
    

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

  pinMode(18, INPUT);
  pinMode(39, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(19, INPUT);
  pinMode(21, INPUT);
  pinMode(22, INPUT);
  pinMode(23, INPUT);


  ads1.begin();
  ads2.begin();
  ads1.setGain(GAIN_ONE); 
  ads2.setGain(GAIN_ONE);   

 Serial.println("D INPUT"); 
  
}




void loop() {


 
Serial.print(digitalRead(18));Serial.print(digitalRead(39));Serial.print(digitalRead(34));Serial.print(digitalRead(35));Serial.print(digitalRead(19));Serial.print(digitalRead(21));Serial.print(digitalRead(22));Serial.print(digitalRead(23));
 Serial.println(""); 

  // Analog read
  
  adcString[0] = String(ads1.readADC_SingleEnded(0));
  adcString[1] = String(ads1.readADC_SingleEnded(1));
  adcString[2] = String(ads1.readADC_SingleEnded(2));
  adcString[3] = String(ads1.readADC_SingleEnded(3));

  adcString[4] = String(ads2.readADC_SingleEnded(0));
  adcString[5] = String(ads2.readADC_SingleEnded(1));
  adcString[6] = String(ads2.readADC_SingleEnded(2));
  adcString[7] = String(ads2.readADC_SingleEnded(3));

  
  
  display.clear();
  buttonString = String(readSwitch());
  display.drawString(0, 0, "A0: ");   display.drawString(20, 0, adcString[0]);
  display.drawString(70, 0, "A1: ");   display.drawString(90, 0, adcString[1]);

  display.drawString(0, 10, "A2: ");   display.drawString(20, 10, adcString[2]);
  display.drawString(70, 10, "A3: ");   display.drawString(90, 10, adcString[3]);

  display.drawString(0, 20, "A4: ");   display.drawString(20, 20, adcString[4]);
  display.drawString(70, 20, "A5: ");   display.drawString(90, 20, adcString[5]);

  display.drawString(0, 30, "A6: ");   display.drawString(20, 30, adcString[6]);
  display.drawString(70, 30, "A7: ");   display.drawString(90, 30, adcString[7]);

  display.drawString(0, 40, "Button: ");   display.drawString(40, 40, buttonString);
  
  display.display();
   
  delay(200); 



  
  

}
