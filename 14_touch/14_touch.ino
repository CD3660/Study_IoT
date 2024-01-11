// 터치센서 핀 정의
const int t = 13;
// 모터 핀 정의
int motorPin1 = 4;  // 모터 드라이버의 IN1에 연결된 핀
int motorPin2 = 5;  // 모터 드라이버의 IN2에 연결된 핀
int speedPin = 3;   // 모터 드라이버의 Enable에 연결된 PWM 핀

void setup() {
  Serial.begin(9600);
  pinMode(t, INPUT);
  // 핀 설정
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(speedPin, OUTPUT);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void loop() {
  // 터치센서 값을 읽어오기
  int touchValue = digitalRead(t);

  // 읽어온 값을 시리얼 모니터에 출력
  Serial.println(touchValue);

  // 터치 감지 여부 확인
  if (touchValue == 1) {
    analogWrite(speedPin, 255);
  } else {
    analogWrite(speedPin, 0);
  }
  delay(10);
}
