## :rocket: Introductie
Als we het hebben over 'Arduino' dan kan dit gaan over verschillende dingen:
1. De software (IDE)
2. De Hardware (UNO of andere Microcontrollers)
3. Het platform (dus het type software en hardware)


Hieronder is beschreven hoe je de Arduino UNO hardware kunt aansluiten en kunt aansturen met de Arduino IDE (Software).
Bovenaan deze pagina zie je twee verschillende setjes code: "Componenten" en "Interactie". Bij Componenten staat de code voor de Sensoren (input) en Actuatoren (output). Bij "Interacties" staan voorbeelden van combinaties tussen Sensoren en Actuatoren. In alle code voorbeelden staat ook hoe je de sensoren en actuatoren kunt aansluiten. 

Wil je een sensor herkennen? Dan kun je hieronder een verwijzing vinden met het overzicht van alle sensoren.

![](imagesGit/board.png)

### :hamburger: Installeren Arduino IDE 
In [deze video](https://youtu.be/mFxqtiRe4xE) doorloop ik onderstaande stappen.

1. Download [Arduino IDE](https://www.arduino.cc/en/software)
2. Sleep deze naar de map 'Applications'
3. Sluit je Arduino UNO aan (via USB)
4. Open de Arduino IDE
5. Stel de Arduino IDE in op Engels (via menu "Preferences")
6. Windows computer: Download en installeer de CH340G driver: [https://electronics-project-hub.com/arduino-not-detected-and-driver-issues-solved/ ](https://sparks.gogo.co.nz/ch340.html)
7. Selecteer Arduino UNO en de poort (/dev/cu.usbmodem ****)
8. Open File > Examples > 01.Basics > Blink
9. Upload deze file naar je Arduino UNO (command + U)
10. Zie je nu "DONE UPLOADING"? Dan werkt je sorftware en hardware perfect. :trophy:

### Test nu de code   
11. Is de upload gelukt? Kijk dan of je een lampje ziet knipperen (tussen de boards van je UNO, 1 seconde aan/1 seconde uit
12. Pas de getallen aan in de code (nu 500 ipv 1000 milliseconden)
13. Upload de code en zie het verschil in knipperen

Werkt het? :trophy: :trophy: :trophy:

### :books: Installeren van libraries
Sommige sensoren of actuatoren gebruiken libraries om de code eenvoudiger leesbaar te houden. Als dit nodig is staat dat in de voorbeeldcode. 

1. Open de tab Libraries: 'Tools > Manage Libraries…' (staat je Arduino IDE nog niet in het Engels? Doe dat dan gelijk even)
2. Zoek naar de juiste library
3. Klik “install” (voor onze projecten is de versie niet van groot belang)

