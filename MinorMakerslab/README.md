## :rocket: Introduction
All ['MicroControllers'](MicroControllers) can be found here. You will also find instructions on how to install them.

Below, you will find all the Sensors and Actuators (output) we have.

Sensors and actuators sometimes have a Grove connector (white plug) and sometimes pins where you need to connect loose (female) wires. If the connection does not match, you can always use an adapter (ask your teacher or Remy).

### :eyes: Sensors

| Name | Sensor | Function | Code Example |
| :---: | :---: | :---: | :---: |
| Distance Sensor | ![Distance Sensor](https://m.media-amazon.com/images/I/51ugwbd5ynL._SL160_.jpg) | This distance sensor emits an ultrasonic sound signal and receives it when the sound is reflected. The time between sending and receiving depends on the distance traveled by the sound signal. This is how the distance to the object is calculated. This sensor is also used in cars as a parking sensor. | [Basic Code](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/AfstandSensor) |
| LED Strip | ![](imagesGit/ledstrip.png) | Each LED can be individually controlled in all RGB colors. There is an adhesive strip so you can easily integrate it into your project (so avoid damaging it). If you use the adhesive strip or integrate it into your project, you must buy it (€5 per strip), so we can purchase new ones for future students. | [Basic Code](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/LED-strip-heen) |
| Light Sensor | ![](imagesGit/licht.png) | The Grove - Light Sensor has an analog output. The brighter the light, the higher the value. Connect the light sensor to the A0 socket. | [Basic Code](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/LightSensor-Simple) |
| Temperature and Humidity | ![](imagesGit/temphu.png) | Measures air temperature and humidity. Test and demonstrate functionality by blowing on the sensor; avoid using a lighter. | [Basic Code](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/DHT-TempHumidity) |
| Blue LED and Push Button | ![](imagesGit/ledknop.png) | This component contains an LED light and a push button. They can be controlled or read independently. | [Basic Code](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/Knop_Led) |
| Accelerometer - Motion Sensor 16g | ![](imagesGit/acceler16.png) | Find the 16g code for this sensor. It measures movement and orientation across three axes (x, y, and z), similar to the sensor in your phone. It can be programmed to recognize gestures and movements or detect taps. | [Basic Code](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/acceler-16-serial) |
| Servo | ![](https://silicio.mx/media/catalog/product/cache/1/small_image/195x195/5e06319eda06f020e43594a9c230972d/r/o/rob08211p/Grove---Servomotor-21.jpg) | The shaft of this 'motor' can rotate 180 degrees and be positioned anywhere within that range. You can prototype movement by making the motor rotate back and forth. Tip: Do not turn the servo completely to its extreme positions to prevent jittering. | [Basic Code](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/ServoSweep) |
| naam | Sensor   | functie   | Code voorbeeld |
| :---:   | :---: | :---: | :---: |
| Afstand sensor| ![Afstand sensor](https://m.media-amazon.com/images/I/51ugwbd5ynL._SL160_.jpg)  | Deze afstandsmeting stuurt een een ultrasoon geluidssignaal uit en ontvangt deze als het geluid weerkaatst is. De tijd tussen versturen en ontvangen is afhankelijk van de afgelegde weg van het geluidssignaal. Zo wordt de afstand tot het object berekend. Deze sensor zit ook in auto’s als parkeersensor. | [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/AfstandSensor)|
| Led Strip | ![](imagesGit/ledstrip.png)   | Elke led kan je individueel aansturen in alle RGB kleuren. Er zit een plakrand aan zodat je hem makkelijk kunt verwerken in je project (dus beschadigen). Gebruik je deze plakrand of verwerkt je hem in je project? Dat geen probleem maar je moet hem dan kopen (5 euro per strip). Dan kunnen we nieuwe kopen voor de aankomende studenten | [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/LED-strip-heen) |
| Lichtsensor | ![](imagesGit/licht.png) | De Grove - lichtsensor heeft een analoge output. Hoe feller het licht is, des te hoger de waarde. Je sluit de lichtsensor aan op het A0 stekkertje. | [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/LightSensor-Simple)|
| Temp. en vocht | ![](imagesGit/temphu.png)   | Deze meet de temperatuur van de lucht en de hoeveelheid vocht in de lucht. Test en demo de werking met blazen in de sensor, liever niet met een aansteker ;-)  | [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/DHT-TempHumidity) |
| Blauwe LED en Drukknop | ![](imagesGit/ledknop.png)    | Dit component bevat een LED lampje en een drukknop. Deze kun je onafhankelijk van elkaar aansturen of uitlezen.   | [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/Knop_Led) |
| Accelerometer - Bewegingsmeter 16g | ![](imagesGit/acceler16.png)  | Zoek bij deze sensor de 16g code. Dit is een sensor die beweging en stand weergeeft over drie assen (x, y en z). Een soortgelijke sensor zit ook in je telefoon. Je kunt ‘m ook programmeren om gebaren en bewegingen te herkennen, of te herkennen als er op getikt wordt. | [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/acceler-16-serial) |
| Servo | ![](https://silicio.mx/media/catalog/product/cache/1/small_image/195x195/5e06319eda06f020e43594a9c230972d/r/o/rob08211p/Grove---Servomotor-21.jpg) | De as van dit ‘motortje’ kan draaien over 180 graden en in elke gewenste positie worden geplaatst. Je kunt ook beweging prototypen door de motor heen en weer te laten draaien. Tip: draai de servo niet helemaal in zijn uiterste van het bereik om te voorkomen dat deze gaat trillen.   | [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/ServoSweep) |
| Trilmotor | ![](imagesGit/tril.png) | Deze vibratiemotor (ook wel haptic motor) wordt gebruikt in smartphones en wearables. Je kunt hiermee informatie voelbaar doorgeven. Je kunt hier ook hoorbare feedback mee maken, door het motortje tegen hard materiaal te laten trillen. Hang je hem bijvoorbeeld tegen een glas, dan heb je een bel.| Gebruik de Blink code en vervang 'LedBuildin' voor de pin waar je de trilmotor aansluit|
| Chainable LED | ![](imagesGit/chainled.png) | Dit component bevat een RGB LED. In de meeste gevallen is de Ledstrip een betere keuze. Een ledstrip heeft dezelfde leds (alleen kleiner) en is gemakkelijker te programmeren. Je kunt ook een ledstrip maken met 1 led. | [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/ChainableLed) |
| MP3 speler met speaker | ![](imagesGit/speaker.png) | Dit component heeft een MP3 module, een geheugenkaart en een speaker. Als je deze speaker in een doosje plaatst kan het behoorlijk luid zijn. Er zijn een beperkt aantal van deze modules beschikbaar bij Remy. Je hebt deze code nodig (onder componenten) MP3_OpenSmart|  [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/MP3_OpenSmart) |
| [Soundsensor Grove](https://wiki.seeedstudio.com/Grove-Sound_Sensor/) | ![](imagesGit/soundSensor.jpg) | Can detect the sound intensity of the environment. The main component of the module is a simple microphone, which is based on the L358 amplifier and an electret microphone. |  [Basiscode](https://wiki.seeedstudio.com/Grove-Sound_Sensor/) |
| [Soundsensor Max 4466](https://lastminuteengineers.com/max4466-arduino-tutorial/) | ![](imagesGit/max4466.jpg) | Meet de geluidsdruk. Dit component is gemaakt rondom een  Electret microfoon en een versterker Max 4466. Code voorbeeld. |  [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/SoundSensor_max4466) |
| [AI sensor](https://wiki.seeedstudio.com/Grove-Vision-AI-Module/) | ![](imagesGit/aiModuleGrove.jpg) | Herkent afbeeldingen en gezichten, je kunt deze module zelf trainen. Belangrijk om te onthouden, gebruik chrome voor het uploaden van modellen. | [Quickstart](https://wiki.seeedstudio.com/Grove-Vision-AI-Module/)|
| [RFID sensor](https://wiki.seeedstudio.com/Grove-125KHz_RFID_Reader/) | ![](imagesGit/RFID.jpg) | Je kunt verschillende RFID tags herkennen | [Basiscode](https://wiki.seeedstudio.com/Grove-125KHz_RFID_Reader/) |
| [Capacative sensor](https://github.com/harmsel/SensorLab/blob/main/SensorenActuatoren/CapacativeSensor/CapacativeSensor.ino) | ![](imagesGit/ ) | Deze meet aanraking en nabijheid van een (deel van) je lichaam. Dus je kunt deze als aanraaksensor of nabijheid sensor gebruiken. Hoe meer aanraking, des te hoger de waarde in je serial monitor | [Basiscode](https://github.com/harmsel/SensorLab/blob/main/SensorenActuatoren/CapacativeSensor/CapacativeSensor.ino) |
| [Moisture sensor (aarde)](https://wiki.seeedstudio.com/Grove-Capacitive_Moisture_Sensor-Corrosion-Resistant/) | ![](imagesGit/moistureSensor.jpg) | Deze meet aanraking en nabijheid van een (deel van) je lichaam. Dus je kunt deze als aanraaksensor of nabijheid sensor gebruiken. Hoe meer aanraking, des te hoger de waarde in je serial monitor | [Basiscode](https://wiki.seeedstudio.com/Grove-Water_Atomization/) |
| [Watervernevelaar](https://wiki.seeedstudio.com/Grove-Water_Atomization/) | ![](imagesGit/waterVernevelaar.jpg) | Deze leg je in een bakje water en zal dan een kleine mist veroorzaken, leuk om met lasers op te stralen. Lasers hebben we ook voldoende. |  [Basiscode](https://wiki.seeedstudio.com/Grove-Water_Atomization/) |
| [Laser](https://www.instructables.com/Laser-Diode-Module-Tutorial/) | ![](imagesGit/laser.jpg) | Deze maakt een klein rood puntje. Samen met een servo kun je hier een automatisch katspeeltje maken. Verder heel goed om [een lichtsluis te maken](https://www.instructables.com/How-to-Make-a-Laser-Security-System-Using-Arduino-/) , of rook rook of nevel de straal zichtbaar te maken. | Sluit aan op een D poort en verander de standaard blink code.|
| [Hart pulse sensor](https://microcontrollerslab.com/pulse-sensor-arduino-tutorial/) | ![](imagesGit/heartPulse.jpg) | Hiermee kun je je hartslag meten door je vinger op de sensor te houden|  [Basiscode](https://microcontrollerslab.com/pulse-sensor-arduino-tutorial/) |
| [RFID - NFC - HW147](https://microcontrollerslab.com/pulse-sensor-arduino-tutorial/) | ![](imagesGit/RFID_HW147.jpg) | Meet verschillende tags/NFC kaarten, je kunt ook de HvA passen gebruiken om verschillende mensen te identificeren. |  [Basiscode](https://github.com/harmsel/SensorLab/tree/main/SensorenActuatoren/RFID_HW-147) |
| [RFID - NFC - HW147](https://wiki.seeedstudio.com/Grove-Vision-AI-Module/) | ![](imagesGit/cameraAI.jpg) | Een AI module met camera |  [QuickStart](https://icthva.sharepoint.com/:w:/s/FDMCI_ORG__CMD-Amsterdam/EXzyY2UQJuhIqKWNUEoHXqgBHttThaawOR97wrSRfN2FuQ?e=BKxhDG) |
| [MP3 speler Grove](https://wiki.seeedstudio.com/Grove-MP3_v2.0/) | ![](imagesGit/MP3-Grove.jpg) | Geluid MP3 speler  Zet geluiden op de Micro SD geheugenkaart. Sluit een losse speaker (die heeft Remy) aan en je hoort geluid |  [Basiscode](https://github.com/harmsel/SensorLab/blob/main/SensorenActuatoren/MP3-Grove/MP3-Grove.ino) |
| [Gesture sensor](https://wiki.seeedstudio.com/Grove-Gesture_v1.0/) | ![](https://files.seeedstudio.com/wiki/Grove_Gesture_V_1.0/img/400px-Gesture_sensor_3.png) | Deze herkent een aantal vooraf ingestelde handgebaren |  [Basiscode](https://wiki.seeedstudio.com/Grove-Gesture_v1.0/) |
| [Relais](https://wiki.seeedstudio.com/Grove-Relay/) | ![](imagesGit/relaisGrove.jpg) | Schakel grote stromen in met een externe voeding |  [Basiscode](https://wiki.seeedstudio.com/Grove-Relay/) |





### :anger: Troubleshooting
Always check **first** whether it's a code or hardware issue:

1. Select the Uno and the Port ("/dev/cu.usbserial**" for MAC or "COM" for Windows)
2. Open a blank sketch (File > New or press 'command + n')
3. Upload this blank sketch (or 'command + u')

**Uploading a blank sketch fails**

1. Is your Port not listed? Swap your hardware (and cable) with your neighbor
2. Using Windows? Install the driver (see the last step under 'Installing Arduino IDE')
3. Connect your Arduino to a different port on your laptop
4. Check [this video](https://youtu.be/C6NZ1WOGFKw) again
5. Visit Remy to see if another hardware version works

**If uploading a blank sketch succeeds**, the errors are caused by issues in your code.

1. Revert to a version that worked before (it's wise to create backups of your files)
2. Check the error message (literal text)
3. Look at where the error occurs (pink bar)
