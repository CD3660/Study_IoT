// 핀 번호 정의
const int buttonPin = 2;  // 버튼 핀
const int ledPin1 = 11;
const int ledPin2 = 10;  // LED 핀

// 변수 선언
int buttonState = 0;      // 버튼 상태 저장 (HIGH 또는 LOW)
int lastButtonState = 0;  // 이전 버튼 상태 저장
int ledState = 0;         // LED 상태 저장 (ON 또는 OFF)
int brightness = 0;

void setup() {
  // 핀 모드 설정
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 버튼 상태 읽기
  buttonState = digitalRead(buttonPin);
  brightness = map(analogRead(0), 0, 1023, 0, 255);
  Serial.println(brightness);

  // 버튼의 상태가 변경되었는지 확인
  if (buttonState != lastButtonState) {
    // 버튼이 눌리면 LED 상태 토글
    if (buttonState == HIGH) {
      ledState++;
    }
  }

  if (ledState % 3 == 0) {
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
  } else if (ledState % 3 == 1) {
    analogWrite(ledPin1, brightness);
    analogWrite(ledPin2, 0);
  } else if (ledState % 3 == 2) {
    analogWrite(ledPin1, brightness);
    analogWrite(ledPin2, brightness);
  }
  delay(50);
  // 현재 버튼 상태를 이전 버튼 상태로 업데이트
  lastButtonState = buttonState;
}