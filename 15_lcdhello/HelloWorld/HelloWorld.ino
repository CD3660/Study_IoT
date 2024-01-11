//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();  // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
}


void loop() {
  for (int posCnt = 0; posCnt < 13; posCnt++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
  for (int posCnt = 0; posCnt < 29; posCnt++) {
    lcd.scrollDisplayRight();
    delay(200);
  }
    for (int posCnt = 0; posCnt < 16; posCnt++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
  for (int i = 0; i < 10; i++) {
    delay(500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hello, world!");
    lcd.setCursor(0, 1);
    lcd.print(millis());
    delay(500);
  }
}
