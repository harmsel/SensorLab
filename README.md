## Introductie
Na het installeren van Arduino en het aansluiten van de hardware kun je deze plek voorbeelden vinden van kant en klare code. In deze code staat ook hoe je de sensoren en actuatoren (output) kunt aansluiten. Hieronder een link naar een pagina met afbeeldingen van de sensorenzodat je weet hoe ze er uit zien.

### Installeren arduino Mac
Volg deze HELLO WORLD video: https://youtu.be/C6NZ1WOGFKw 
Let op: sommige Arduino boards hebben een rode led in plaats van een groene

### Installeren arduino windows
Soms herkent windows je arduino board niet en moet je, na het volgen van deze video: https://youtu.be/C6NZ1WOGFKw onderstaand artikel doornemen: https://electronics-project-hub.com/arduino-not-detected-and-driver-issues-solved/.

### Overzicht van alle sensoren
https://docs.google.com/document/d/1kRWXyL-nMneFP8WJKPnR6a4RMJA-kljxb1RygZhN2KE/edit

### Fouten oplossen

#### Code uploaden lukt niet
“Problem uploading to board” 
“can’t open device’ 



##### Windows: 
Upload een lege sketch om zeker te weten dat het aan de code ligt (en niet aan de hardware)
Ga naar tools > Port 
Selecteer de juiste com poort
Niet gevonden? volg “Port not found” Windows
##### Mac: 
Upload een lege sketch om zeker te weten dat het aan de code ligt (en niet aan de hardware)
Ga naar tools > Port 
Selecteer de ”/dev/cu.usbserial**’ port (kijk evt. nogmaals naar het install video: https://youtu.be/C6NZ1WOGFKw ) 

##### Andere foutmelding (code problemen)
Upload een lege sketch om zeker te weten dat het aan de code ligt (en niet aan de hardware)
Kijk rondom welke regel het fout gaat (is roze en regel staat in de foutmelding)
De meeste foutmeldingen gaan over fout plaatsen van { of } en een regel die niet eindigd met ;
