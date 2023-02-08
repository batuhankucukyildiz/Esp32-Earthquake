#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
WiFiClient wifiClient;
String host = "api.thingspeak.com";
int httpPort = 80;  
String url = "/apps/thingtweet/1/statuses/update";

HTTPClient http; 

void setup() 
{
  Serial.begin(9600);
  WiFi.begin("XXXXXXX", "XXXXXX");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("ESP CONNECTED");
  Serial.println(WiFi.localIP());
  http.begin(wifiClient,host,httpPort,url); 
  String RequestBody = "api_key=XXXXXXXXX&status=Kiram Sokak No:6 Daire:12 Acil Yardim Gerekiyor";
  int httpCode = http.POST(RequestBody);
  Serial.println(httpCode);
  delay(2000);
}

void loop() 
{
  
}
