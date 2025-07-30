#include <Arduino.h>

int MotorLeftEnablePin = 3;
int MotorLeftPositivePin = 5;
int MotorLeftNegativePin = 6;

int MotorRightEnablePin = 11;
int MotorRightPositivePin = 10;
int MotorRightNegativePin = 9;

void blinkBuiltInLED(int times, int delayTime)
{
  for (int i = 0; i < times; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayTime);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayTime);
  }
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(MotorLeftEnablePin, OUTPUT);
  pinMode(MotorLeftPositivePin, OUTPUT);
  pinMode(MotorLeftNegativePin, OUTPUT);

  pinMode(MotorRightEnablePin, OUTPUT);
  pinMode(MotorRightPositivePin, OUTPUT);
  pinMode(MotorRightNegativePin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Starting the Arduino application...");
}

void loop()
{
  blinkBuiltInLED(3, 500);

  digitalWrite(MotorLeftPositivePin, HIGH);
  digitalWrite(MotorLeftNegativePin, LOW);
  analogWrite(MotorLeftEnablePin, 200);

  digitalWrite(MotorRightPositivePin, HIGH);
  digitalWrite(MotorRightNegativePin, LOW);
  analogWrite(MotorRightEnablePin, 200);

  delay(2000);

  digitalWrite(MotorRightPositivePin, LOW);
  digitalWrite(MotorRightNegativePin, HIGH);
  analogWrite(MotorRightEnablePin, 200);

  digitalWrite(MotorLeftPositivePin, LOW);
  digitalWrite(MotorLeftNegativePin, HIGH);
  analogWrite(MotorLeftEnablePin, 200);
}
