#include <ESP32Servo.h>

// Pin Setup
const int irSensorPin = 33;
const int rainSensorPin = 32;
const int servoPin = 26;

const int redLed = 27;
const int yellowLed = 14;
const int greenLed = 12;

const int buzzerPin = 25;

Servo pemilah;

void setup() {
  Serial.begin(115200);

  pinMode(irSensorPin, INPUT);
  pinMode(rainSensorPin, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pemilah.attach(servoPin);

  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
  pemilah.write(90);
}

void loop() {
  bool adaSampah = digitalRead(irSensorPin) == LOW;

  if (adaSampah) {
    Serial.println("Sampah Terdeteksi! Memverifikasi...");

    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);

    unsigned long startTime = millis();
    bool tetapAdaSampah = true;

    while (millis() - startTime < 1500) {
      if (digitalRead(irSensorPin) == HIGH) {
        tetapAdaSampah = false;
        Serial.println("Sampah hilang sebelum waktunya, dibatalkan.");
        break;
      }
      delay(10);
    }

    if (tetapAdaSampah) {
      bool sampahBasah = digitalRead(rainSensorPin) == LOW;

      if (sampahBasah) {
        Serial.println("Sampah Basah");
        pemilah.write(40);
      } else {
        Serial.println("Sampah Tidak Basah");
        pemilah.write(135);
      }

      digitalWrite(redLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(greenLed, LOW);

      digitalWrite(buzzerPin, HIGH);
      delay(2500);
      digitalWrite(buzzerPin, LOW);
      pemilah.write(90);
    }
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
    pemilah.write(90);
  }

  delay(100);
}
