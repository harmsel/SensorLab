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
