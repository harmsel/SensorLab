/************** FUNCTIE winddata ophalen *****************/
void WifiEnDataOphaal() {

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  LEDsWifi();

  Serial.println(F("Connecting..."));
  delay(1000);

  // Connect to HTTP server
  client.setTimeout(10000);
  if (!client.connect("yogapadma.nl", 80)) {
    Serial.println(F("Connection failed"));
    return;
  }

  Serial.println(F("Connected!"));

  // Send HTTP request
  client.println(F("GET /wind/aeolusFeed.php HTTP/1.0"));
  client.println(F("Host: yogapadma.nl"));

  client.println(F("Connection: close"));
  if (client.println() == 0) {
    Serial.println(F("Failed to send request"));
    client.stop();
    return;
  }

  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  // It should be "HTTP/1.0 200 OK" or "HTTP/1.1 200 OK"
  if (strcmp(status + 9, "200 OK") != 0) {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    client.stop();
    return;
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders)) {
    Serial.println(F("Invalid response"));
    client.stop();
    return;
  }

  // Allocate the JSON document
  // Use https://arduinojson.org/v6/assistant to compute the capacity.
  DynamicJsonDocument doc(7000);

  // Parse JSON object
  DeserializationError error = deserializeJson(doc, client);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    client.stop();
    return;
  }

  JsonArray voorspellingen = doc["voorspellingen"];//Array aanmaken van de json string
  int itemsArray = doc["voorspellingen"].size(); //hoeveel voorspellingen bevat de Array?
  Serial.print(" - items in Array:");   Serial.println(itemsArray);


  int sunSet[] = {0, 17, 18, 19, 20, 21, 22, 22, 21, 20, 19, 17, 16}; // ---- sunset/maand? eerste is 0, want dan is januari nr 1 in array
  bool volgendeDag = false; // zodat de uur leds niet uitgaan bij volgnde dag

  /**************** STARTPOSITIE VAN DE DATA NAAR LEDS IN DE STRIP  ***********************/
  int LedPos;
  int eersteVoorspelling = doc["voorspellingen"][0]["uur"].as<int>();
  int ledOffset = eersteVoorspelling - 10; //Data van 10 uur moet op led positie 0

  /***************    Volgende dag laten zien, twee uur voordat het donker is ***************/
  int huidigUur = doc["voorspellingen"][itemsArray - 1]["huidigUur"].as<int>();
  int huidigMaand = doc["voorspellingen"][itemsArray - 1]["huidigMaand"].as<int>();
  Serial.print("huidigUur: ");   Serial.print(huidigUur);
  Serial.print(" huidigMaand: ");   Serial.println(huidigMaand);

  if (huidigUur >= (sunSet[huidigMaand] - 2)) {
    ledOffset = ledOffset - 13;    // leds aanzetten met de offzet van voorspellingen
    volgendeDag = true;
  }


  /**************** HAAL DE DATA UIT DE JSON EN ZET NAAR DE JUISTE LEDJES  ***********************/
  for (int x = 0; x < itemsArray - 1; x++) { //Laaste in Json bevat tijd dus -1
    int VoorspellingHour = doc["voorspellingen"][x]["uur"].as<int>();
    int VoorspellingWind = doc["voorspellingen"][x]["wind"].as<int>();

    LedPos = ledOffset + x;
    Serial.print("LedPos="); Serial.print(LedPos);
    if (LedPos < 0) {
      // doe niks: leds aansturen op een negatieve positie = CRASHHHH!!
      Serial.print(" Negatief ");

    } else if (huidigUur > 22 || huidigUur < 6) { //ALLE Leds uitzetten als het nacht is
      leds[LedPos] = CRGB::Black;
      Serial.print(" Het is Nu nacht, dus de Aeolus mag uit");

    } else if (VoorspellingHour > sunSet[huidigMaand]) { //Voorspelling na donker niet weergeven
      leds[LedPos] = CRGB::Black;
      Serial.print(" Zon is Onder ");

    } else if ((huidigUur >= LedPos + 10) && !volgendeDag) { // leds uitzetten die geweest zijn
      leds[LedPos] = CRGB::Black;
      Serial.print(" verstreken tijd ");

    } else if (VoorspellingWind > 30) {
      leds[LedPos].setRGB(250, 0, 250);
      Serial.print(" >30 paars");

    } else if (VoorspellingWind > 20) {
      leds[LedPos].setRGB(250, 0, 0);
      Serial.print(" >20 rood ");

    } else if (VoorspellingWind > 16) {
      leds[LedPos].setRGB(250, 250, 0);
      Serial.print(" > 16kn geel ");

    } else  if (VoorspellingWind > 14) {
      leds[LedPos].setRGB(0, 250, 0);
      Serial.print(" > 14kn Groen ");

    } else {
      leds[LedPos].setRGB(0, 0, 250);
      Serial.print(" < 14kn blauw");

    }
    FastLED.show();
    delay(50);

    /* ------ Voor debuggen en testen ------------*/
    Serial.print(". Hour: ");   Serial.print(VoorspellingHour);
    Serial.print(" . Wind: ");   Serial.println(VoorspellingWind);

    // Disconnect
    client.stop();
  }
}
