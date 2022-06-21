# Variables Ambientales
Este Proyecto fue diseñado como proyecto final de curso aplicando IoT (Internet de las Cosas), donde podremos obtener variables
ambientales como: Temeperatura ambiental, humedad ambiental, presion y una aproximacion de Altitud monitoriando todos estos valores 
en tiempo real por medio de una pagina con la IP local. 
El dispositivo contiene:
- Dev Kit ESP32
- NeoPixeles
- Sensor SHT30 Analogico
- Sensor BME680
- Pantalla OLED


# ¿Cómo funciona?
Funciona por medio de una tarjeta microcontrolador ESP32 el cual posee conectividad WiFi y Bluetooth, el cual puede ser programado con difentes lenguajes de programación como C, C++ , en este caso se utilizó Arduino IDE 


# ¿Qué podemos hacer?
Desplegar la información por medio de la plataforma Web con la IP local y usando conexión Wifi, donde podremos obtener
la temperatura, la Humedad, Presion, Una aproximación de Altitud y reistencia de Gas  para ello nos conectaremos a la IP local de nuestro
Internet y el Led NeoPixel que actuara como indicadores para las mediciones.


# Descripción de pines 

### Pantalla OLED SH1106G, Temperatura, Humedad, Presion y Aproximacion de Altitud – Comunicación I2C
| Referencia   | SH1106G  | SHT30    | BME680   |
| :---         |    :---: |    ---:  | ------   |
| ESP32        | SCL IO22 | SCL IO22 | SCL IO32 |
|              | SCL IO23 | SDA IO23 | SDA IO33 |



| SSD 1306 | SHT30    | BME680   |
| -------- | -----    | -------- |
| SCL IO22 | SCL IO22 | SCL IO32 |
| SDA IO23 | SDA IO23 | SDA IO33 |

### LED Neopixel - Comunicación SPI
| Referencia | WS2812B |
| -------- | -----  |
|  ESP32   |  IO12  |
|    5V    |  VCC   |
|   GND    |  GND   |
               
# Licencia
Hardware License: CERN OHL v1.0 para más información visitar el siguiente [Link][CERN_v1].
[CERN_v1]: https://ohwr.org/project/cernohl/wikis/Documents/CERN-OHL-version-1.2
Software License: GPL v3
Documentation License: CC BY 4.0 International
