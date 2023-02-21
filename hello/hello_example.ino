void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //啟動序列以115200速率
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World!");  //印出資訊 println的ln代表跳行
  delay(1000);  //暫停1000ms=1s
}

//ctrl+T 可以自動排版
