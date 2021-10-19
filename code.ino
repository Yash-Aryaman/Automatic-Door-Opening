#include <Servo.h>
int servoPin = 3; 
Servo Servo1;
const int trigPin = 4;
const int echoPin = 5;
long duration;
int distance;
int redPin= 2;
int greenPin = 7;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
pinMode(redPin, OUTPUT);
digitalWrite(redPin,LOW);
pinMode(greenPin, OUTPUT);
digitalWrite(greenPin,LOW);
Servo1.attach(servoPin);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
  if (distance < 30) {
    digitalWrite(greenPin,HIGH);
    Servo1.write(90);
  }
  else{
    digitalWrite(greenPin,LOW);
    Servo1.write(0);
  }
  if (distance >= 30) {
    digitalWrite(redPin,HIGH);
  }
  else{
    digitalWrite(redPin,LOW);
  }
}
void setColor(int redValue, int greenValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
}
