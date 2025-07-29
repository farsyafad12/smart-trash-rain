#include <Servo.h>

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

  // Awal status
  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
  pemilah.write(90); // posisi netral
}

void loop() {
  bool adaSampah = digitalRead(irSensorPin) == LOW; // LOW artinya ada benda
  if (adaSampah) {
    Serial.println("Sampah Terdeteksi!");
    
    // Lampu kuning nyala
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);

    delay(500); // jeda proses deteksi

    bool sampahBasah = digitalRead(rainSensorPin) == LOW; // LOW = Basah

    if (sampahBasah) {
      Serial.println("Sampah Basah");
      pemilah.write(45); // putar kiri
    } else {
      Serial.println("Sampah Tidak Basah");
      pemilah.write(135); // putar kanan
    }

    // Lampu hijau nyala
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);

    // Buzzer bunyi sebentar
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);

    delay(2000); // tunggu sebelum reset
    pemilah.write(90); // kembali ke tengah

    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
  }

  delay(100);
}
