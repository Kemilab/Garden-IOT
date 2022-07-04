
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL9el6nXZd"
#define BLYNK_DEVICE_NAME "Garden IOT"

#define BLYNK_FIRMWARE_VERSION        "0.3.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
int senzor = A0;
int vlaga;
int map_low = 533;
int map_high = 200;
int postotak;
int prosjek;
int brojac = 0;

void podatci(){
 if(brojac < 10){
  vlaga = analogRead(senzor);
  prosjek += vlaga;
  brojac++;
 }if(brojac == 10){
  prosjek = prosjek / 10;
  prosjek = vlaga;
 }
  delay(1000);
  postotak = map(vlaga, map_low, map_high, 0, 100);
 Blynk.virtualWrite(V1, postotak);
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  podatci();
}
