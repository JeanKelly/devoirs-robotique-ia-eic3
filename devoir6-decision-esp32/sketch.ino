#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22
#define LED_PIN 2
#define BUZZER_PIN 4

const float SEUIL = 30.0;   // seuil en °C

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  dht.begin();
  Serial.println("Systeme pret. Seuil = 30 C");
}

void loop() {
  // 1. MESURER
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Erreur de lecture du capteur!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // 2. COMPARER et 3. AGIR
  if (temperature > SEUIL) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
    Serial.println("ALERTE: temperature trop elevee!");
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    Serial.println("Normal.");
  }

  delay(2000);
}
