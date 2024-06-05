//download https://github.com/elechouse/PN532
// unzip
// Zoek de 'PN532' en de 'N532_SWHSU' folder (in de geunzipte folder)
// verplaats beide folders in de library folder van je computer (Documents/Arduino/libraries)
// Sluit de draad naar SCL aan op pin 2, SDA aan op pin 3 (zitten in grove connector D2)

#include <SoftwareSerial.h>
#include <PN532_SWHSU.h>
#include <PN532.h>
SoftwareSerial SWSerial( 3, 2 ); // RX, TX
 
PN532_SWHSU pn532swhsu( SWSerial );
PN532 nfc( pn532swhsu );
String tagId = "None", dispTag = "None";
byte nuidPICC[4];
 
void setup(void)
{
  Serial.begin(9600);
  Serial.println("Hello Maker!");
  //  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata)
  {
    Serial.print("Didn't Find PN53x Module");
    while (1); // Halt
  }
  // Got valid data, print it out!
  Serial.print("Found chip PN5");
  Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. ");
  Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.'); 
  Serial.println((versiondata >> 8) & 0xFF, DEC);
  // Configure board to read RFID tags
  nfc.SAMConfig();
  //Serial.println("Waiting for an ISO14443A Card ...");
}
 
 
void loop()
{
  readNFC();
}
 
 
void readNFC()
{
  boolean success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                       // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  if (success)
  {
    Serial.print("UID Length: ");
    Serial.print(uidLength, DEC);
    Serial.println(" bytes");
    Serial.print("UID Value: ");
    for (uint8_t i = 0; i < uidLength; i++)
    {
      nuidPICC[i] = uid[i];
      Serial.print(" "); Serial.print(uid[i], DEC);
    }
    Serial.println();
    tagId = tagToString(nuidPICC);
    dispTag = tagId;
    Serial.print(F("tagId is : "));
    Serial.println(tagId);
    Serial.println("");
    delay(1000);  // 1 second halt
  }
  else
  {
    // PN532 probably timed out waiting for a card
    Serial.println("Timed out! Waiting for a card...");
  }
}
String tagToString(byte id[4])
{
  String tagId = "";
  for (byte i = 0; i < 4; i++)
  {
    if (i < 3) tagId += String(id[i]) + ".";
    else tagId += String(id[i]);
  }
  return tagId;
}