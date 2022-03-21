// Date and time functions using a DS3231 RTC connected via I2C and Wire lib


/*

* Hardware : NORVI IIOT-AE01-R / IIOT-AE01-T  / IIOT-AE02-V / IIOT-AE02-I

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

 *    (src: https://github.com/adafruit/RTClib)  or

 *    (src:)

 *    EDIT I2C connections of wire library Wire.begin() to Wire.begin(16,17)
 
*/
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {

  Serial.begin(115200);

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
     //rtc.adjust(DateTime(2019, 11, 25, 11,25, 0));
  }
  //rtc.adjust(DateTime(2019, 11, 25, 11,25, 0));
}

void loop () {
    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

 
    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");

    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now + TimeSpan(7,12,30,6));

    Serial.print(" now + 7d + 30s: ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();

    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");

    Serial.println();
    delay(1000);
}
