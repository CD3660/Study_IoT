#define R 9
#define G 10
#define B 11

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    while (Serial.available()) {
      switch (Serial.read()) {
        case 'r':
          digitalWrite(R, HIGH);
          break;
        case 'g':
          digitalWrite(G, HIGH);
          break;
        case 'b':
          digitalWrite(B, HIGH);
          break;
      }
      delay(10);
    }
  }
}
