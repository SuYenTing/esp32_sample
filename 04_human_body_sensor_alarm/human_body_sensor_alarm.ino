void setup() {
  
  Serial.begin(115200);
  pinMode(5, OUTPUT);  // ISD1820錄放音模組輸出
  pinMode(18, INPUT);  // HW-416紅外線感應模組輸入
}

void loop() {

  int value = digitalRead(18);  // 讀取紅外線感應模組輸入值
  
  Serial.println(value);  // 印出紅外線感應模組輸入值
  
  if (value == 1) {
    
    Serial.println("發出告警");
    
    // 模擬ISD1820錄放音模組"按一下"
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);
  }
}
