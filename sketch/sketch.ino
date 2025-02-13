#include <NewPing.h>

// Ultrasonic sensor
#define TRIGGER_PIN  6  // Pin trigger sensor
#define ECHO_PIN     5  // Pin echo sensor

#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters).
unsigned int distance;  // ตัวแปรสำหรับเก็บค่าระยะ sensor

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Sensor setup

void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{
  delay(10);  // Wait 10ms between pings

  // อ่านค่าระยะจาก sensor
  distance = sonar.ping_cm(); 
  Serial.print("Sensor : ");
  Serial.print(distance);
  Serial.print(" cm");

  // การทำงานของ sensor
  if (distance > 20 && distance <= 100  ) // ระยะ 20 - 100 cm
  {
    Serial.println("OK"); 
  } 



}



