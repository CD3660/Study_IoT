// 모터 핀 정의
int motorPin1 = 4;  // 모터 드라이버의 IN1에 연결된 핀
int motorPin2 = 5;  // 모터 드라이버의 IN2에 연결된 핀
int speedPin = 3;   // 모터 드라이버의 Enable에 연결된 PWM 핀

void setup() {
  // 핀 설정
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(speedPin, OUTPUT);
}

void loop() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(speedPin, 255);
  delay(2000);
  analogWrite(speedPin, 0);
  delay(1000);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin1, LOW);
  analogWrite(speedPin, 80);
  delay(2000);
    analogWrite(speedPin, 0);
  delay(1000);
}
