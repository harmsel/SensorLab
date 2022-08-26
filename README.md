## Introductie
Na het installeren van Arduino en het aansluiten van de hardware kun je deze plek voorbeelden vinden van kant en klare code. Deze bestaat uit twee delen:: "Basics-components" en "Basics-interactions". In de een vind je code voor alle losse componenten, je moet echter zelf code toevoegen voor het laten samenwerken van input en output. Onder Basics-interactions staat voorbeeldcode waarbij combinaties zijn gemaakt tussen sensoren en actuatoren (output). Wil je een andere sensor gebruiken of meersere soorten output aan een sensor hangen, dan kun je code gebruiken uit 'basics-components(In deze code staat ook hoe je de sensoren en actuatoren (output) kunt aansluiten. Hieronder een link naar een pagina met afbeeldingen van de sensorenzodat je weet hoe ze er uit zien.

### Installeren arduino Mac
Volg deze HELLO WORLD video: https://youtu.be/C6NZ1WOGFKw 
Let op: sommige Arduino boards hebben een rode led in plaats van een groene

### Installeren arduino windows
Soms herkent windows je arduino board niet en moet je, na het volgen van deze video: https://youtu.be/C6NZ1WOGFKw onderstaand artikel doornemen: https://electronics-project-hub.com/arduino-not-detected-and-driver-issues-solved/.

### Overzicht van alle sensoren
https://docs.google.com/document/d/1kRWXyL-nMneFP8WJKPnR6a4RMJA-kljxb1RygZhN2KE/edit

### Fouten oplossen

#### Code uploaden lukt niet
Krijg je na het uploaden onderstaande melding in de  oranje balk?

![](https://docs.m2stud.io/cs/arduino/images/%28Arduino_Tutorials%29_Arduino_Upload_Fail.png)


1. Open een lege sketch (File > New) en upload deze lege sketch 
2. Ga naar tools > Port
3. Selecteer de juiste Port ”/dev/cu.usbserial**’MAC of com (Windows) 
4. Staat deze Port er niet bij? Ruil dan je hardware (en kabel) even met je Buur
5. Je kunt ook proberen de Arduino opnieuw aan je Laptop aan te sluiten (als je geen buur hebt)
6. Kijik nogmaals naar https://youtu.be/C6NZ1WOGFKw ) 


##### Andere foutmelding (code problemen)
Upload een lege sketch. Krijg je in de oranje balk "Problem Uploading..." dan is het een probleem met verbinden/drivers. Krijg je een andere foutmelding dan zit het probleem in de Sketch (code).
Kijk rondom welke regel het fout gaat (is roze en regel staat in de foutmelding)
De meeste foutmeldingen gaan over fout plaatsen van { of } en een regel die niet eindigd met ;
