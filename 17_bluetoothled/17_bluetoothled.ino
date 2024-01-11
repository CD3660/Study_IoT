#include <SoftwareSerial.h>

SoftwareSerial BT(8, 7);  // RX:7, TX:8 => 연결 반대로

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  while (BT.available()) {
    char ch = BT.read();
    if (ch == '1') {
      digitalWrite(2, 1);
    } else if (ch == '2') {
      digitalWrite(2, 0);
    }
  }

  while (Serial.available()) {
    char ch = Serial.read();
    if (ch == '1') {
      digitalWrite(2, 1);
    } else if (ch == '2') {
      digitalWrite(2, 0);
    }
  }
}
