#include <ESP8266WiFi.h>

#include <ArduinoJson.h>
#include <elapsedMillis.h>
#define FASTLED_INTERNAL // Pragma messages uitzetten, mooet voor de include van fastled staan om rare van Fastled uit te zetten
#include <FastLED.h>

/******************************* LED strip *****************************/
#define DATA_PIN     D5 //Dat is D5
#define BRIGHTNESS  50 //initiele helderheid
#define NUM_LEDS 45 //aantal leds, iets meer want als je niet bestaande leds adresseerd: CRASHHHH!
CRGB leds[NUM_LEDS];

/**************************** INIT ***********************************/
bool firstRun = true; //voor testen, haalt gelijk data op en niet pas na interval
const char* JsonURL = "http://yogapadma.nl/wind/aeolusFeed.php";
//const char* JsonURL = "http://supplement.nl/wind/aeolusDataTest.json";

elapsedMillis teller1; //maak teller1 aan, voor de tijd tussen het ophalen van data

/******************************* WIFI *********************************/
const char* ssid = ".::Gratissss Wijfie::.";
const char* pass = "hildeenmikazijnsnoepjes";
//
//const char* ssid ="IOT";     // your network SSID (name)
//const char* pass = "!HVAIOT!"; // your network key

//const char* ssid ="Hutspot";
//const char* pass = "88888888";

WiFiClient client;
