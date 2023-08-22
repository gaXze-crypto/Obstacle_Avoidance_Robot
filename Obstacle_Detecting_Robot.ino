// C++ code
//
#include <Servo.h>

int LDistance = 0;

int RDistance = 0;

Servo servo_6;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo_6.attach(6, 500, 2500);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  servo_6.write(90);
  if (0.01723 * readUltrasonicDistance(13, 12) < 20) {
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    delay(500); // Wait for 500 millisecond(s)
      digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    servo_6.write(0);
    LDistance = 0.01723 * readUltrasonicDistance(13, 12);
    delay(500); // Wait for 500 millisecond(s)
    servo_6.write(180);
    RDistance = 0.01723 * readUltrasonicDistance(13, 12);
    delay(1000); // Wait for 1000 millisecond(s)
    if (RDistance >= LDistance) {
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(1, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    } else {
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(1, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    }
  } else {
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }
}
