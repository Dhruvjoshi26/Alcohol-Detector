#include<LiquidCrystal.h>

const int alcoholSensorPin = A0;  // Analog pin for MQ-135 sensor
const int buzzerPin = A4; 
const int ledpin = 13;        // Digital pin for the buzzer

bool alcoholDetected = false;  // Flag to track if alcohol is detected

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Pin configuration for the LCD

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD
  pinMode(alcoholSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read alcohol sensor value
  int alcoholValue = analogRead(alcoholSensorPin);

  // Convert analog value to voltage
  float voltage = (alcoholValue / 1023.0) * 5.0;

  // Map the voltage to a percentage (adjust the mapping as needed)
  float alcoholPercentage = map(voltage, 0.5, 4.0, 0, 100);
  alcoholPercentage = constrain(alcoholPercentage, 0, 100);  // Ensure the value is within 0-100%

  // Print alcohol level to LCD
  //lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("alcohol level: ");
  lcd.print(alcoholPercentage);
  lcd.print("%");

  // Check if alcohol level is above a certain threshold (adjust as needed)
  if (alcoholPercentage >5.0&& !alcoholDetected) {
    // If alcohol is detected and not previously detected, beep the buzzer once
    beepBuzzer(9);
    
    alcoholDetected = true;  // Set the flag to true to avoid repeated beeping
    // Print drunk message to LCD
    lcd.setCursor(0, 1);
    lcd.print("Drunk!");
  } 
  else if (alcoholPercentage <= 5.0) {
    // If alcohol is not detected, reset the flag
    alcoholDetected = false;
    lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("Alco Level: ");
  lcd.print(alcoholPercentage);
  lcd.print("%");
     lcd.setCursor(0, 1);
    lcd.print("       ");
  }

  delay(1000);  // Adjust the delay as needed
}

// Function to produce beep patterns
void beepBuzzer(int beeps) {
  for (int i = 0; i < beeps; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(200);  // Adjust the duration of the beep
    digitalWrite(buzzerPin, LOW);
    delay(200);  // Adjust the duration of silence between beeps
  }
}
