// RGB LED 핀 설정
#define R 9    // 빨간색 핀
#define G 10   // 초록색 핀
#define B 11   // 파란색 핀

int rainbow = 0;

void setup() {
  // RGB LED 핀을 출력으로 설정
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  rainbow += 10;

  // sin() 함수의 출력 범위를 -1에서 1로 제한하고 map() 함수를 사용하지 않음
  float rFloat = sin(radians(rainbow)) * 127.5 + 127.5;
  float gFloat = sin(radians(rainbow + 120)) * 127.5 + 127.5;
  float bFloat = sin(radians(rainbow + 240)) * 127.5 + 127.5;

  // 실수 값을 정수로 변환
  int rValue = int(rFloat);
  int gValue = int(gFloat);
  int bValue = int(bFloat);

  Serial.print("r: ");
  Serial.print(rValue);
  Serial.print(", g: ");
  Serial.print(gValue);
  Serial.print(", b: ");
  Serial.println(bValue);

  analogWrite(R, rValue);
  analogWrite(G, gValue);
  analogWrite(B, bValue);

  delay(100);
}
