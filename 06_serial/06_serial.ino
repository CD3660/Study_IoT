int count = 0;
String str = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    count++;
    Serial.print(count);
    Serial.print(" : ");
    Serial.println(c);
    str += c;
    delay(10);
  }
  
  if (str != "") {
    Serial.println(str);
    str = "";
  }
}
