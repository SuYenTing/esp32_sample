//twgo.io/dht11
//u8g2 oled下載連結：twgo.io/obdgp 
//U8g2-2.27.6版本: 使用舊版本是為中文造字
#include <SimpleDHT.h>

// for DHT11,
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2

#include "Wire.h" //i2c 21,22
#include "U8g2lib.h" //請下載u8g2程式庫
//OLED 螢幕解析度為128*64
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// U8G2_SSD1306_128X64_NONAME_F_HW_I2C為OLED型號

void setup() {
  Serial.begin(115200);
  u8g2.begin();//初始化
  u8g2.enableUTF8Print();//啟用 UTF8字集
  u8g2.setFont(u8g2_font_unifont_t_chinese1);//設定使用中文字形
  u8g2.setDrawColor(1);//設定顏色，我們是單色只有1
  u8g2.setFontPosTop();//座標從上開始
  u8g2.setFontDirection(0);//0不旋轉、1->90、2->180、3->270
}

void loop() {
  
  //OLED顯示文字
  u8g2.clear();//顯示前清除螢幕
  u8g2.setCursor(0, 10);//移動游標
  u8g2.print(String("經過測試，畫面可").c_str());//寫入文字
  
  u8g2.setCursor(0, 30);//移動游標
  u8g2.print(String("寫三排，每排可以").c_str());

  u8g2.setCursor(0, 50);//移動游標
  u8g2.print(String("放入八個中文字。").c_str());
  
  //送到螢幕顯示
  u8g2.sendBuffer();
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
