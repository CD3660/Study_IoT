int ranNum = 0;
int myNum = 0;
#define R 9
#define G 10

void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  randomSeed(analogRead(A0));

  makingRan();
}

void loop() {
  if (Serial.available()) {
    myNum = Serial.parseInt();
    Serial.print(myNum);
    if (ranNum == myNum) {
      Serial.println(" good");
      digitalWrite(G, 1);
      delay(1000);
      digitalWrite(G, 0);
      makingRan();
    } else {
      Serial.println(" no");
      digitalWrite(R, 1);
      delay(1000);
      digitalWrite(R, 0);
    }
  }
}
void makingRan() {
  Serial.println("making random number...");
  Serial.println("start");
  ranNum = random(1, 10);
}
