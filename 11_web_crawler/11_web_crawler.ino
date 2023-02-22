//t.ly/86qm
//幾個重要的地方
//1. 原本使用httpclient就改成WiFiClientSecure
//2. 不知道是不是內容較多，原本使用client.readstring會讀取不完整，因此改成一行一行讀取client.readStringUntil('\n')

#include <WiFiClientSecure.h>
#include <ArduinoJson.h>//使用JSON函式庫

char SSID[] = "[WiFi裝置名稱]"; //請修改為您連線的網路名稱
char PASSWORD[] = "[WiFi密碼]"; //請修改為您連線的網路密碼
char host[] = "data.epa.gov.tw";
//申請API key 環保署： https://data.epa.gov.tw/api-term
char url[] = "/api/v2/aqx_p_432?offset=0&limit=1000&format=json&api_key=[輸入API KEY]";  // Server URL

WiFiClientSecure client;

void setup() {
  Serial.begin(115200);
  //連線到指定的WiFi SSID
  Serial.print("Connecting Wifi: ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  //連線成功，顯示取得的IP
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  client.setInsecure(); //若使用ESP32 1.0.6核心須加上這句避免SSL問題
}

void loop() {
  Serial.println("啟動網頁連線");
  if (client.connect(host, 443)) {
    Serial.println("連線成功，開始讀取內容");
    // Make a HTTP request:
    client.print("GET "); client.print(url); client.println(" HTTP/1.0"); //1.1改成1.0
    client.print("Host: "); client.println(host);//
    client.println("Connection: close");
    client.println();
    //等候回應
    delay(2000);

    Serial.println("\n讀取表頭");
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      Serial.println(line);
      if (line == "\r") {
        Serial.println("\n表頭結束");
        break;
      }
    }

    Serial.println("\n讀取原始內容---------");
    String payload = "";    
    while (client.connected()) {
      client.setTimeout(1000);
      //一次讀取一句，如果只使用readString會讀取不完
      String line = client.readStringUntil('\n');
      //去除空白字元
      line.trim(); line.replace("\r\n", "");
      Serial.print(line);
      payload += line ;
    }
    Serial.println("\n原始內容結束----------");
    
    payload = "[" + payload + "]"; //將JSON物件轉換成JSON陣列
    Serial.println("\nPayload=");
    Serial.println(payload);
    //JSON解析
    DynamicJsonDocument AQJarray(50000);
    deserializeJson(AQJarray, payload);//解析payload為JSON Array格式
    Serial.println("一共有 " + String(AQJarray[0]["fields"].size()) + " 欄位");
    Serial.println("一共有 " + String(AQJarray[0]["records"].size()) + " 站所");
    for (int i = 0; i <= AQJarray[0]["records"].size(); i++) {
      //尋找siteid=45的臺南安南站所
      if (AQJarray[0]["records"][i]["siteid"] == "45") {
        String Str_AQIValue = AQJarray[0]["records"][i]["aqi"];
        String Str_Sitename = AQJarray[0]["records"][i]["sitename"];
        Serial.println(Str_Sitename + "AQI: " + Str_AQIValue);        
        //int Int_AQIValue = Str_AQIValue.toInt(); //轉整數給後續判斷用
      }
    }
    Serial.println("完成，關閉連線...");
    client.stop();//斷線，否則只能傳5次
  }
  else {
    Serial.println("連線失敗...請再重試一次");
  }
  delay(20000);
}
