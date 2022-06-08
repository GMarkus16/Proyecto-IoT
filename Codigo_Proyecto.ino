#include "Adafruit_SHT31.h"
Adafruit_SHT31 sht31 = Adafruit_SHT31();
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_Neopixel.h>
#define SCREEN_WIDTH 128 // Display de Oled en Pixeles
#define SCREEN_HEIGHT 64 // Display de Oled en Pixeles
#define i2c_Address 0x3c
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#define I2C_SDA 33
#define I2C_SCL 32
#define SEALEVELPRESSURE_HPA (1013.25)
TwoWire I2CBME = TwoWire(0);
Adafruit_BME280 bme;
Adafruit_Neopixel pixeles = Adafruit_Neopixel(6, 12, NEO_GRB + NEO_KHZ800); 

unsigned long delayTime;


void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println(F("BME280 test"));
  I2CBME.begin(I2C_SDA, I2C_SCL, 100000);
  Serial.println("SHT31 test");
  pixeles.begin();
  pixeles.show();
  if (! sht31.begin(0x44)) {   
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }
  if (!display.begin(i2c_Address, true)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);
  display.clearDisplay();

  bool status;

  status = bme.begin(0x76, &I2CBME);
  if (!status){
    Serial.println("no se ha encontado BME280, revisar direccion y coneccion");
    while(1);
  }
  Serial.println("-- Default Test --");
  delayTime = 1000;

  Serial.println();
}
void loop() {
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();
  Serial.print("Temperatura = ");
  Serial.print(bme.readTemperature());// lectura de temperatura BME280
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);//lectura de  presion
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));// aproximacion de altitud 
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());// humedad
  Serial.println(" %");

  Serial.println();
  
  pixeles.setBrightness(20);
  for(int i = 0; i<6; i++){
    pixeles.setPixelColor(i, 0, 255, 0);
    pixeles.show();
    delay(500);
  }
  
  if (! isnan(t)) { 
    Serial.print("Temperatura  = "); Serial.print(t); Serial.println("°C");
  }
  else {
    t = 0.0;
    Serial.println("Failed to read temperature");
  }

  if (! isnan(h)) {  
    Serial.print("Humedad  = "); Serial.print(h); Serial.println("%");
  }
  else {
    h = 0.0;
    Serial.println("Failed to read humidity");
  }
  Serial.println();
  delay(500);
  display.clearDisplay();

  // display temperature
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 7);
  display.println("Temperatura:");
  display.println();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 18);
  display.print(t); display.println(" C");
  // display humidity
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 40);
  display.println("Humedad:");
  display.println();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 50);
  display.print(h); display.println(" %");
  // display presion
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(20,7);
  display.println("Presion:");
  display.println();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(20, 50);
  display.print(bme.readPressure() / 100.0F); display.println(" hPa");
  // display Altitud
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(20, 40);
  display.println("Altitud:");
  display.println();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(20, 50);
  display.print(bme.readAltitude(SEALEVELPRESSURE_HPA); display.println(" m");
  delay(1000);
  display.display();


}
