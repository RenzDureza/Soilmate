// Libraries
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup() {

  lcd.init();
  lcd.backlight();

  dht.begin();



}

void loop() {

  delay(100);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.setCursor(15, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.setCursor(12, 1);
  lcd.print("C");


}
