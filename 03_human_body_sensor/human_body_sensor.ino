void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(18, INPUT);  // HW-416紅外線感應模組輸入
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(18);  // 讀取18腳位數值
  Serial.println(value);  // 印出結果 HIGH=1=true, LOW=0=false
  delay(500);  // 暫停0.5秒
}
