## Introductie
Na het installeren van Arduino en het aansluiten van de hardware kun je op deze plek voorbeelden vinden van kant en klare code. Hierboven zie je twee verschillende setjes code: "Basics-components" en "Basics-interactions". Onder Basics-interactions staat voorbeeldcode waarbij combinaties zijn gemaakt tussen sensoren en actuatoren (output). Wil je een andere sensor gebruiken of meersere soorten output aan een sensor hangen? Dan kun je code gebruiken uit 'basics-components'. In de code voorbeelden staat ook hoe je de sensoren en actuatoren (output) kunt aansluiten. Wil je een sensor herkennen? Dan kun je hieronder een verwijzing vinden met het overzicht van alle sensoren.

### Installeren arduino Mac
Volg deze HELLO WORLD video: https://youtu.be/C6NZ1WOGFKw 
Let op: sommige Arduino boards hebben een rode led in plaats van een groene

### Installeren arduino windows
Soms herkent windows je arduino board niet en moet je, na het volgen van deze video: https://youtu.be/C6NZ1WOGFKw onderstaand artikel doornemen: https://electronics-project-hub.com/arduino-not-detected-and-driver-issues-solved/.

### Overzicht van alle sensoren
Afstand sensor:
![Afstand sensor](https://m.media-amazon.com/images/I/51ugwbd5ynL._SL160_.jpg)

Servo:
![](https://silicio.mx/media/catalog/product/cache/1/small_image/195x195/5e06319eda06f020e43594a9c230972d/r/o/rob08211p/Grove---Servomotor-21.jpg)


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
