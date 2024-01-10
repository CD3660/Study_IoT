// 핀 번호 정의
const int buttonPin = 2;  // 버튼 핀
const int ledPin1 = 13;
const int ledPin2 = 12;    // LED 핀

// 변수 선언
int buttonState = 0;      // 버튼 상태 저장 (HIGH 또는 LOW)
int lastButtonState = 0;  // 이전 버튼 상태 저장
int ledState = 0;       // LED 상태 저장 (ON 또는 OFF)

void setup() {
  // 핀 모드 설정
  pinMode(buttonPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // 버튼 상태 읽기
  buttonState = digitalRead(buttonPin);

  // 버튼의 상태가 변경되었는지 확인
  if (buttonState != lastButtonState) {
    // 버튼이 눌리면 LED 상태 토글
    if (buttonState == HIGH) {
      ledState++;
      if(ledState%3 == 0){
        digitalWrite(ledPin1, 0);
        digitalWrite(ledPin2, 0);
      } else if(ledState%3 == 1){
        digitalWrite(ledPin1, 1);
        digitalWrite(ledPin2, 0);
      } else if(ledState%3 == 2){
        digitalWrite(ledPin1, 1);
        digitalWrite(ledPin2, 1);
      }
    }
    delay(50); // 디바운스를 위한 짧은 지연 시간
  }

  // 현재 버튼 상태를 이전 버튼 상태로 업데이트
  lastButtonState = buttonState;
}