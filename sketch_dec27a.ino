/* Weather monitoring system with the New Blynk app Home Page */

// Include the library files
#define BLYNK_TEMPLATE_ID "TMPL3_3eWvYaR"
#define BLYNK_TEMPLATE_NAME "Weather Monitoring System"
#define BLYNK_AUTH_TOKEN "mr-mFobM8CSbU8tZKeqHOORQDyMrPqVw"
#define BLYNK_PRINT Serial

#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = "mr-mFobM8CSbU8tZKeqHOORQDyMrPqVw";
char ssid[] = "Abhi Prakash";
char pass[] = "123456789";

#define DHTPIN 2  
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}

void setup() {
  Serial.begin(921600); //Initialize serial communication with a baud rate of 9600
  Blynk.begin(auth, ssid, pass); // Initialize Blynk
  dht.begin();// Initialize DHT sensor
  timer.setInterval(1000L, DHT11sensor);  // Update every 1 second
}

void loop() {
  Blynk.run();
  timer.run();
}