
#define LED_PIN11 11
#define LED_PIN10 10

void setup() {
  // 핀 모드를 출력으로 설정
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(LED_PIN11, OUTPUT);
  pinMode(LED_PIN10, OUTPUT);
}

void loop() {
   // LED의 밝기를 0에서 255까지 변화시키면서 조절
  for (int brightness = 0; brightness <= 255; brightness+=8) {
    analogWrite(LED_PIN11, brightness);
    delay(15); // 각 단계별로 10밀리초의 지연
  }

  // LED의 밝기를 255에서 0까지 변화시키면서 조절
  for (int brightness = 255; brightness >= 0; brightness-=8) {
    analogWrite(LED_PIN11, brightness);
    delay(15); // 각 단계별로 10밀리초의 지연
  }
     // LED의 밝기를 0에서 255까지 변화시키면서 조절
  for (int brightness = 0; brightness <= 31; brightness+=1) {
    analogWrite(LED_PIN10, brightness);
    delay(15); // 각 단계별로 10밀리초의 지연
  }

  // LED의 밝기를 255에서 0까지 변화시키면서 조절
  for (int brightness = 31; brightness >= 0; brightness-=1) {
    analogWrite(LED_PIN10, brightness);
    delay(15); // 각 단계별로 10밀리초의 지연
  }
}