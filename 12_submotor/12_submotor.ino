#include <Servo.h>

Servo myservo;  // 서보모터 객체 생성

const int trigPin = 2;   // 초음파 센서 Trig 핀
const int echoPin = 3;   // 초음파 센서 Echo 핀
const int servoPin = 9;  // 서보모터 제어 핀

int interval = 3;    // 타임스탬프 시작 시간
int lastMillis = 0;  // 경과 시간

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(servoPin, OUTPUT);

  myservo.attach(servoPin);  // 서보모터에 연결된 핀 설정
  myservo.write(180);        // 초기에 서보모터를 0도로 설정
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

  // 거리를 시리얼 모니터에 출력
  Serial.print("거리: ");
  Serial.print(distance);
  Serial.println(" cm");

  // 거리에 따라 서보모터 제어
  if (distance <= 20) {
    if (millis() / 1000 - lastMillis >= interval) {
      myservo.write(60);
    }
  } else {
    myservo.write(180);
    lastMillis = millis() / 1000;
  }
}
