const int trigPin = 2;    // Trig 핀
const int echoPin = 3;    // Echo 핀
const int buzzerPin = 9;  // 부저 핀

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
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

  // 거리에 따라 부저 제어
  if (distance > 30) {
    noTone(buzzerPin);  // 30cm 이상이면 소리 없음
    delay(100);
  } else if (distance <= 30 && distance > 20) {
    tone(buzzerPin, 494, 200);  // 20cm에서 30cm: C 음
    delay(600);            // 0.5초 동안 대기
  } else if (distance <= 20 && distance > 15) {
    tone(buzzerPin, 494, 200);  // 20cm에서 30cm: C 음
    delay(400);            // 0.5초 동안 대기
  } else if (distance <= 15 && distance > 10) {
    tone(buzzerPin, 494, 200);  // 20cm에서 30cm: C 음
    delay(200);            // 0.5초 동안 대기        // 0.25초 동안 대기
  } else {
    tone(buzzerPin, 494);
    delay(100);
  }

  // 거리를 시리얼 모니터에 출력
  Serial.print("거리: ");
  Serial.print(distance);
  Serial.println(" cm");
}
