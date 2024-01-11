//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int trigPin = 2;  // Trig 핀
const int echoPin = 3;  // Echo 핀

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
}


void loop() {
  long duration, distance;

  // 초음파 센서에 파장을 보냄
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo 핀에서 초음파 수신 시간 측정
  duration = pulseIn(echoPin, HIGH);

  // 거리 계산 (음속 = 343m/s, 2로 나누는 이유는 왕복 거리이므로)
  distance = duration * 0.0343 / 2;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(distance);
  lcd.print("cm");

  delay(200);
}
