/*
 * MOTOR-BOARD Simple Test Sketch
 * Target: ESP32-S3-WROOM-1
 *
 * Tests the shared control pins (A1-A12) that are wired in parallel to:
 *   - 2x TB6612FNG (DC motor drivers)
 *   - 4x A4988 stepper driver footprints
 *   - 8x Servo outputs (A1-A8)
 *
 * Since A1-A12 are shared between drivers via the 3-way selector switches,
 * make sure the switches are set to the matching mode (DC / Stepper / Servo)
 * before running the corresponding test, and that the driver/servo rail
 * (VCC / battery input) is powered.
 *
 * Open Serial Monitor at 115200 baud, then send:
 *   1 -> GPIO toggle test (A1-A12)   - generic continuity/output check
 *   2 -> Servo sweep test (A1-A8)    - needs ESP32Servo library
 *   3 -> Stepper test (Stepper 1: A1=ENABLE, A2=STEP, A3=DIR)
 *   4 -> DC motor test (M1: A1=PWMA, A3=AIN1, A4=AIN2)
 */

#include <Arduino.h>
#include <ESP32Servo.h>


const int pinA[12]      = {1, 2, 15, 4, 5, 6, 7, 22, 8, 9, 10, 11};
const char* pinName[12] = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","A11","A12"};

void allLow() {
  for (int i = 0; i < 12; i++) {
    digitalWrite(pinA[i], LOW);
  }
}

void printMenu() {
  Serial.println();
  Serial.println("MOTOR-BOARD Test Sketch");
  Serial.println("1: GPIO toggle test (A1-A12)");
  Serial.println("2: Servo sweep test (A1-A8)");
  Serial.println("3: Stepper test (Stepper 1: A1=EN, A2=STEP, A3=DIR)");
  Serial.println("4: DC motor test (M1: A1=PWMA, A3=AIN1, A4=AIN2)");
  Serial.println("Send a number to run a test:");
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  for (int i = 0; i < 12; i++) {
    pinMode(pinA[i], OUTPUT);
    digitalWrite(pinA[i], LOW);
  }

  printMenu();
}
void gpioToggleTest() {
  Serial.println("Running GPIO toggle test...");
  for (int i = 0; i < 12; i++) {
    Serial.printf("Toggling %s (GPIO%d)\n", pinName[i], pinA[i]);
    digitalWrite(pinA[i], HIGH);
    delay(300);
    digitalWrite(pinA[i], LOW);
    delay(200);
  }
  Serial.println("Done.");
}
void servoSweepTest() {
  Servo servos[8];
  Serial.println("Running servo sweep test on A1-A8...");

  for (int i = 0; i < 8; i++) {
    servos[i].setPeriodHertz(50);
    servos[i].attach(pinA[i], 500, 2400);
  }

  for (int pos = 0; pos <= 180; pos += 10) {
    for (int i = 0; i < 8; i++) servos[i].write(pos);
    delay(100);
  }
  for (int pos = 180; pos >= 0; pos -= 10) {
    for (int i = 0; i < 8; i++) servos[i].write(pos);
    delay(100);
  }

  for (int i = 0; i < 8; i++) servos[i].detach();
  Serial.println("Done.");
}
void stepperTest() {
  Serial.println("Running stepper test (Stepper 1)...");

 
  digitalWrite(pinA[0], LOW);  
  digitalWrite(pinA[2], HIGH); 

  for (int i = 0; i < 200; i++) {  
    digitalWrite(pinA[1], HIGH);
    delayMicroseconds(800);
    digitalWrite(pinA[1], LOW);
    delayMicroseconds(800);
  }

  digitalWrite(pinA[0], HIGH); 
  Serial.println("Done.");
}

void dcMotorTest() {
  Serial.println("Running DC motor test (M1)...");

  digitalWrite(pinA[2], HIGH);
  digitalWrite(pinA[3], LOW);  

  for (int duty = 0; duty <= 255; duty += 5) {
    analogWrite(pinA[0], duty);
    delay(50);
  }
  for (int duty = 255; duty >= 0; duty -= 5) {
    analogWrite(pinA[0], duty);
    delay(50);
  }

  digitalWrite(pinA[2], LOW);
  digitalWrite(pinA[3], LOW);
  Serial.println("Done.");
}
void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    allLow();

    switch (c) {
      case '1': gpioToggleTest(); break;
      case '2': servoSweepTest(); break;
      case '3': stepperTest();    break;
      case '4': dcMotorTest();    break;
      default: break; 
    }

    printMenu();
  }
}
