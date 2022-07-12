 
Installeren arduino
Installatie video HELLO WORLD 

Foutmeldingen oplossen
Code uploaden lukt niet
“Problem uploading to board” 
“can’t open device’ 

Windows: 
Ga naar tools > Port 
Selecteer de juiste com poort
Niet gevonden? volg “Port not found” Windows
Mac: 
Ga naar tools > Port 
Selecteer de ”/dev/cu.usbserial**’ port (kijk evt. nogmaals naar het installatiefilmpje) 

Andere foutmelding (code problemen)
Upload een lege sketch om zeker te weten dat het aan de code ligt (en niet aan de hardware)
Kijk rondom welke regel het fout gaat (is roze en regel staat in de foutmelding)
De meeste foutmeldingen gaan over fout plaatsen van { of } en een regel die niet eindigd met ;

Board aansluitingen
Alle D (D1 t/m D9) poorten kunnen hetzelfde. A0 is voor een analoge sensor. UART en I2C gebruiken we niet voor deze cursus

Seeeduino


Verschil tussen sensoren en Actuatoren
Sensoren kunnen iets waarnemen. (sens van Senses = zintuigen)
Actuatoren kunnen iets weergeven.(Actuator doet iets, to Act)
Voor interactie met een gebruiker heb je altijd beiden nodig. Toch?

Installeren van libraries
Sommige sensoren of actuatoren gebruiken libraries om de code eenvoudiger leesbaar te houden. Het installeren van een library doe je zo:

Ga naar Sketch > Include Library > Manage Libraries…

Zoek naar de naam van je component of library:


Klik “install” (voor onze projecten is de versie niet van groot belang)
Sluit Library Manager
Ga naar File > Examples
Scroll helemaal naar beneden
Controleer of er voorbeelden bij zijn gekomen met de naam van je sensor of actuator


Afstandsensor
Deze afstandsmeting stuurt een een ultrasoon geluidssignaal uit en ontvangt deze als het geluid weerkaatst is. De tijd tussen versturen en ontvangen is afhankelijk van de afgelegde weg van het geluidssignaal. Zo wordt de afstand tot het object berekend. Deze sensor zit ook in auto’s als parkeersensor.

RGB LEDstrip - Neopixel
Deze zit in je kitje. Wil je hem verwerken in je project (dus beschadigen) is dat geen probleem maar je moet hem dan kopen (5 euro per strip). Dan kunnen we nieuwe kopen voor de aankomende studenten





Vibratie Motor/trilmotor

 
Deze vibratiemotor (ook wel haptic motor) wordt gebruikt in smartphones en wearables. Je kunt hiermee informatie voelbaar doorgeven. Je kunt hier ook hoorbare feedback mee maken, door het motortje tegen hard materiaal te laten trillen. Hang je hem bijvoorbeeld tegen een glas, dan heb je een bel.

De Servomotor



De as van dit ‘motortje’ kan draaien over 180 graden en in elke gewenste positie worden geplaatst. Je kunt ook beweging prototypen door de motor heen en weer te laten draaien. Tip: draai de servo niet helemaal in zijn uiterste van het bereik om te voorkomen dat deze gaat trillen.
 
 
gLDR - LichtSensor
De Grove - lichtsensor heeft een analoge output. Hoe feller het licht is, des te hoger de waarde. 
Aansluiten op A0
Zie afbeelding bovenaan dit document






Accelerometer - Bewegingsmeter

Dit is een sensor die beweging en stand weergeeft over drie assen (x, y en z). Een soortgelijke sensor zit ook in je telefoon. Je kunt ‘m ook programmeren om gebaren en bewegingen te herkennen, of te herkennen dat er op getikt wordt.

Leuke voorbeeld projecten 
https://www.seeedstudio.com/Grove-3-Axis-Digital-Accelerometer-16g.html (onder ‘Learn’)
Aansluiten poort: I2C
Zie afbeelding bovenaan dit document



Temperatuur & Luchtvochtigheid

Vaker voorkomende problemen
Deze sensor bestaat in verschillende versies (DT11 of DT12). Je kunt op deze pagina (https://www.seeedstudio.com/catalogsearch/result/?q=DHT) zien welke jij hebt.


Blauwe LED
Dit component bevat een LED lampje en een drukknop. Deze kun je onafhankelijk van elkaar aansturen of uitlezen.

Aansluiten op stekker D3






 


Drukknop
Dit component bevat een LED lampje en een drukknop. Deze kun je onafhankelijk van elkaar aansturen of uitlezen.

Aansluiten op stekker D3



 
 

Chainable led


Dit component bevat een RGB LED. Je kunt de kleur en de helderheid instellen. In een aantal gevallen is de Ledstrip een makkelijkere keuze. De RGB led is wel fijn om in te bouwen in je prototype

Aansluiten op stekker D7
en op de ‘IN’ stekker!
Je kunt deze led doorverbinden, dus als je 4 leds wilt hebben, dan maak je een ketting (OUT naar IN). Vandaar de naam Chainable led.






Library installeren
 Je moet hiervoor de ‘Grove - Chainable RGB LED’ library installeren. 

