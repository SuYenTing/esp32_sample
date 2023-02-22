void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(36, INPUT);  // 光敏電阻
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(36);
  Serial.println(value);
  delay(100);
}
