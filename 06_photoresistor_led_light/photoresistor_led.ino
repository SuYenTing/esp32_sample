void setup() {

  Serial.begin(115200);
  pinMode(36, INPUT);  // 4pin光敏電阻
  pinMode(39, INPUT);  // 4pin雨滴電阻
  pinMode(4, OUTPUT);  // 4號腳位:綠燈
  pinMode(16, OUTPUT); // 16號腳位:黃燈
  pinMode(17, OUTPUT); // 17號腳位:紅燈
}

void loop() {

  int value = analogRead(36);  // 讀取光敏電阻類比數值
  int rain = analogRead(39);  // 讀取雨滴電阻類比數值
  Serial.println(String(value) + "," + String(rain));  // 印出數值

  // 光敏電阻數值大(即環境暗)亮三個燈
  if (value >= 2000) {
    digitalWrite(4, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(17, HIGH);
  }
  else if (value >= 1000) {
    digitalWrite(4, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(17, LOW);
  }
  else if (value >= 500) {
    digitalWrite(4, HIGH);
    digitalWrite(16, LOW);
    digitalWrite(17, LOW);
  }
  // 光敏電阻數值小(即環境明亮)滅三個燈
  else {
    digitalWrite(4, LOW);
    digitalWrite(16, LOW);
    digitalWrite(17, LOW);
  }

  delay(500);
}
