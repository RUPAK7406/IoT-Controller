#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include <Firebase.h>

#define FIREBASE_HOST "finalproject-2d2d7.firebaseio.com"                         
#define FIREBASE_AUTH "5LAgH52OmgEdUZtImtweHiOyC4FutAPbd1o0J1gH"                  
#define WIFI_SSID "Wifi-student"                                           
#define WIFI_PASSWORD "1234567890" 


int ledPower = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(ledPower, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ledStatus = Firebase.getInt("ledStatus");
  if(ledStatus == 1){
    digitalWrite(ledPower, HIGH);
  } else {
    digitalWrite(ledPower, LOW);
  }

  //set data:
  //Firebase.set(ledStatus, "1");
}
