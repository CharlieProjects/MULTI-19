
// #include <SSD1306.h>
#include <SH1106.h>

// =============== SETTINGS ===================
//  create display(Adr, SDA-pin, SCL-pin) 

#ifdef SSD1306_h
SSD1306 display(0x3c, 5, 4); // GPIO 5 = D1, GPIO 4 = D2
#else
#ifdef SH1106_h
SH1106 display(0x3c, 5, 4); // GPIO 5 = D1, GPIO 4 = D2
#endif

#define flipDisplay false



void displayStart(){
  if (flipDisplay)
    display.flipScreenVertically();

  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "===MULTI-19===");
  display.drawString(0, 16, "MultiploColombia");
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 40, "Copyright (c) 2020");
  display.drawString(0, 50, "CARLIE PROJECTS");
  display.display();
  delay(2500);
}