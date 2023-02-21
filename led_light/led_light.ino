void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);  // 4號腳位:綠燈
  pinMode(16, OUTPUT); // 16號腳位:黃燈
  pinMode(17, OUTPUT); // 17號腳位:紅燈
  pinMode(5, OUTPUT); // 5號腳位:ISD1820錄放音模組輸出
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4, HIGH);  // 亮綠燈
  delay(1000);
  digitalWrite(4, LOW);  // 熄綠燈

  digitalWrite(16, HIGH);  // 亮黃燈
  delay(1000);
  digitalWrite(16, LOW);  // 熄黃燈

  digitalWrite(5, HIGH);  // 發出聲音

  digitalWrite(17, HIGH);  // 亮紅燈
  delay(1000);
  digitalWrite(17, LOW);  // 熄紅燈

  digitalWrite(5, LOW);  // 關閉聲音
}
