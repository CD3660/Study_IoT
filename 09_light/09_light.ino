#define light A0
#define G 10

void setup() {
  pinMode(G, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (analogRead(light) <= 500) {
    analogWrite(G, map(analogRead(light), 200, 500, 255, 0));
  } else {
    digitalWrite(G, 0);
  }
}
