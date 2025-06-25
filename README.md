# Alcohol-Detector
# 🍷 Alcohol Detector using Arduino Uno

## 🔍 Project Overview

This project is an **Alcohol Detection System** built using an **MQ-3 Gas Sensor** and **Arduino Uno**. It is designed to detect the presence of alcohol in a person’s breath and trigger a buzzer or LED alert if the alcohol level exceeds a certain threshold.

This project can be used in:
- Vehicle ignition interlock systems
- Workplace safety checks
- Educational demonstration of gas sensor technology

---

## ⚙️ Components Used

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno            | 1        |
| MQ-3 Alcohol Sensor    | 1        |
| Buzzer                 | 1        |
| Red LED                | 1        |
| Green LED (optional)   | 1        |
| Resistors (220Ω)       | 2        |
| Breadboard             | 1        |
| Jumper Wires           | As needed |
| USB Cable (for Arduino)| 1        |

---

## 🧠 Working Principle

- The **MQ-3 sensor** detects alcohol concentration from a person’s breath.
- The analog output of the sensor is read by the Arduino.
- If the sensor value exceeds a certain threshold (indicating presence of alcohol), the system activates a buzzer and/or LED warning system.
- Otherwise, it remains idle or shows a green LED.

---

## 🔌 Circuit Diagram

**Connections:**

| MQ-3 Sensor Pin | Connects To           |
|------------------|----------------------|
| VCC              | 5V (Arduino)         |
| GND              | GND (Arduino)        |
| AOUT             | A0 (Analog Input)    |

**Other connections:**
- Buzzer: Digital Pin 9
- Red LED: Digital Pin 8
- Green LED (optional): Digital Pin 7

---

## 🧾 Arduino Code

```cpp
const int sensorPin = A0;
const int buzzerPin = 9;
const int redLedPin = 8;
const int greenLedPin = 7;

int sensorValue = 0;
int threshold = 400; // adjust based on calibration

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Alcohol Level: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }

  delay(1000);
}
