#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <ESP8266WiFi.h>

char auth[] = "LnuSxlg9mZMWkh5PyywXn9VFTox69qKa";
char ssid[] = "Julliana";
char pass[] = "lumpiaseller";

#define sensor A0
#define waterPump D3
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

bool Relay = 0;

void setup() {
	Serial.begin(9600);
	Serial.begin(115200);

	pinMode(waterPump, OUTPUT);
	digitalWrite(waterPump, HIGH);

	dht.begin();

	Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

	timer.setInterval(100L, soilMoistureSensor);
	timer.setInterval(100L, sendSensor);
}

BLYNK_WRITE(V1) {
	Relay = param.asInt();
	if (Relay == 1) {
		digitalWrite(waterPump, LOW);
	} else {
		digitalWrite(waterPump, HIGH);
	}
}

void soilMoistureSensor() {
	int value = analogRead(sensor);
	value = map(value, 0, 1024, 0, 100);
	value = (value - 100) * -1;
	Blynk.virtualWrite(V0, value);
}

void sendSensor() {
	float h = dht.readHumidity();
	float t = dht.readTemperature();
	if (isnan(h) || isnan(t)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}

	Blynk.virtualWrite(V2, t);
	Blynk.virtualWrite(V3, h);
	Serial.print("Temperature: ");
	Serial.print(t);
	Serial.print("    Humidity: ");
	Serial.println(h);
}

void loop() {
	Blynk.run();
	timer.run();
}
