# Proyecto-IoT
Este Proyecto fue diseñado como proyecto final de curso aplicando IoT (Internet de las Cosas), donde podremos obtener variables
ambientales como: Temeperatura ambiental, humedad ambiental, presion y una aproximacion de Altitud monitoriando todos estos valores 
en tiempo real por medio de Node-RED. 
El dispositivo contiene:
- ESP32
- NeoPixeles
- Sensor SHT30
- Sensor BME280
- Pantalla OLED
# ¿Cómo funciona?
Funciona por medio de una tarjeta microcontrolador ESP32 el cual posee conectividad WiFi y Bluetooth, el cual puede ser programado con difentes lenguajes de programación como C, C++ , en este caso se utilizó Arduino 
# ¿Qué podemos hacer?
Desplegar la información por medio de la plataforma Node-RED usando conexión Wifi, donde podremos obtener
la temperatura, la Humedad, Presion y Una aproximación, desde la misma plataforma
podremoos controlar las cargas AC utilizando sus Relay, por ello utilizando el buzzer y el Led NeoPixel que actuaran
como indicadores para las aplicaciones.
# Descripción de pines 
### Pantalla OLED SH1106G, Temperatura, Humedad, Presion y Aproximacion de Altitud – Comunicación I2C
| Referencia   | SH1106G  | SHT30    | BME280 |
| :---         |    :---: |    ---:  | ------ |
| ESP32        | SCL IO22 | SCL IO22 |
|              | SCL IO23 | SDA IO23 |
| SSD 1306 | SHT30 |
| -------- | ----- |
| SCL IO22 | SCL IO22 |
| SDA IO23 | SDA IO23 |
### Control Cargas AC 
| Referencia   | Carga 1 | Carga 2 | Carga 3 |
| :---         |    :---:|    ---: | ---:    |
| ESP32        |  IO25   |  IO26   |   IO27  |
### LED Neopixel - Comunicación SPI
| Referencia | WS2812B |
| -------- | ----- |
|  ESP32   |  SD3  |
|    5V    |  VCC  |
|   GND    |  GND  |
### Buzzer 
| Referencia   |  Buzzer | 
| :---         |   :---: |
| ESP32        |    IO5  |        
### Monitoreo Cargas AC 
| Referencia   | SCT 013  | Voltaje AC | 
| :---         |   :---:  |  ---:      |
| ESP32        |    IO15  |    IO2     |
|              |   ADC2_2 | ADC2_3     |
               
# Licencia
Hardware License: CERN OHL v1.0 para más información visitar el siguiente [Link][CERN_v1].
[CERN_v1]: https://ohwr.org/project/cernohl/wikis/Documents/CERN-OHL-version-1.2
Software License: GPL v3
Documentation License: CC BY 4.0 International
