int ledPin = 13;

void setup() {
  // 핀 모드를 출력으로 설정
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // LED를 켜고 1초 동안 대기
  digitalWrite(ledPin, HIGH);
  delay(500);

  // LED를 끄고 1초 동안 대기
  digitalWrite(ledPin, LOW);
  delay(500);
}