//code written by yeu1-1 21/11/20

#include <Adafruit_NeoPixel.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include <SPI.h>

#define PIN D3 //set what pin the led strip is connected to
#define NUMPIXELS 60 //set the number of leds to match what is in your led strip
#define BLYNK_PRINT Serial
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Go to the Project Settings (nut icon).
char auth[] = "AUTH CODE";//type your authentication code here 

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "your wifi network";//type the wifi network you want to connect to here 
char pass[] = "wifi network password";// type your wifi network's password here

void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pixels.begin();
}
BLYNK_WRITE(V3)
{

int R = param[0].asInt();
int G = param[1].asInt();
int B = param[2].asInt();
Serial.println(R);
Serial.println(G);
Serial.println(B);

for(int i=0;i<NUMPIXELS;i++){

pixels.setPixelColor(i, pixels.Color(R,G,B));

pixels.show();
}
}

void loop()
{
Blynk.run();
}
