#include <NewPing.h>

// กำหนดโน้ตเสียง (ค่าความถี่ใน Hz)
#define NOTE_C4  262 // C4
#define NOTE_D4  294 // D4
#define NOTE_E4  330 // E4
#define NOTE_F4  349 // F4
#define NOTE_G4  392 // G4
#define NOTE_A4  440 // A4
#define NOTE_B4  494 // B4

//เสียงแจ้งเตือนแบบเรียบง่าย (Simple Alert)
#define NOTE_C5  523 // C5

//เสียงแจ้งเตือนแบบไต่ระดับ (Ascending Alert)
#define NOTE_C5  523 // C5
#define NOTE_D5  587 // D5
#define NOTE_E5  659 // E5

//เสียงแจ้งเตือนแบบฉุกเฉิน (Urgent Alert)
#define NOTE_C6  1047 // C6

//เสียงไซเรนของรถพยาบาล
#define NOTE_A4  440 // A4
//#define NOTE_D5  587 // D5

// Ultrasonic sensor
#define TRIGGER_PIN  6  // Pin trigger sensor
#define ECHO_PIN     5  // Pin echo sensor

#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters).

// กำหนดพินสำหรับการใช้งานเสียง
const int buzzerPin = 9;  // พินสำหรับเสียง sensor
unsigned int distance;  // ตัวแปรสำหรับเก็บค่าระยะ sensor

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Sensor setup

void setup() 
{
  Serial.begin(9600); 
  pinMode(buzzerPin, OUTPUT); // กำหนดพิน output สำหรับเสียง sensor
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
    playTone(buzzerPin, NOTE_E4, distance); //ok 
    Serial.println("playTone"); 
  } 
  else 
  {
    noToneManual(buzzerPin); // หยุดเสียง sensor
  }
}

// ฟังก์ชันสร้างเสียงแบบกำหนดเอง
void playTone(int pin, int frequency, int duration) 
{
  int period = 1000000 / frequency; // คำนวณคาบเวลา (ไมโครวินาที)
  int pulse = period / 2; // ความกว้างของพัลส์
  unsigned long startTime = millis();
  while (millis() - startTime < duration) 
  {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(pin, LOW);
    delayMicroseconds(pulse);
  }
}

// ฟังก์ชันหยุดเสียง
void noToneManual(int pin) 
{
  digitalWrite(pin, LOW); // ปิดพิน
}


