Ultrasonic Distance Sensor with Buzzer and LED Alert

This project uses an ultrasonic distance sensor (HC-SR04) to measure distance and trigger a buzzer and LED based on proximity. It is useful for obstacle detection, parking assistance, and similar applications.



Features

  -Measures distance using an ultrasonic sensor.

  -Alerts with a buzzer at different frequencies based on distance.

  -Controls an LED for visual indication of proximity.

  -Displays distance readings via the serial monitor.



Components Required

  -Arduino board

  -HC-SR04 ultrasonic sensor

  -Buzzer

  -LED

  -Resistors and jumper wires

 

Circuit Diagram

  -TRIGGER_PIN (3) → Connect to HC-SR04 TRIG

  -ECHO_PIN (2) → Connect to HC-SR04 ECHO

  -Buzzer (4) → Connect to a digital pin

  -LEDS (8) → Connect to an LED

  -Code

 

The main program reads the distance from the sensor and activates the buzzer and LED based on the detected range.

	#include "NewPing.h"

	#define TRIGGER_PIN 3
	#define ECHO_PIN 2
	#define MAX_DISTANCE 400  
	#define LEDS 8

	NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
	float duration, distance;
	int buzzer=4;

	void setup() {
  	Serial.begin(9600);
  	pinMode(buzzer,OUTPUT);
  	pinMode(LEDS,OUTPUT);
	}

	void loop() {
  	distance = sonar.ping_cm();
  	Serial.print("Distance = ");
  	if (distance >= 400 || distance <= 2)
  	{
    	Serial.println("Out of range");
 	 }
  	else
  	{
    	Serial.print(distance);
    	Serial.println(" cm");

    	if(distance < 10){
      	digitalWrite(LEDS,HIGH);
      	analogWrite(buzzer,1000);
      	delay(1000);
    	}
    	else if(distance < 30){
      	digitalWrite(LEDS,LOW);
      	analogWrite(buzzer,1000);
      	delay(50);
      	analogWrite(buzzer,0);
     	 	delay(50);
   	 }
   	 else if(distance < 50){
      digitalWrite(LEDS,LOW);
      analogWrite(buzzer,1000);
      delay(100);
      analogWrite(buzzer,0);
      delay(100);
    }
    else if(distance < 100){
      digitalWrite(LEDS,LOW);
      analogWrite(buzzer,1000);
      delay(100);
      analogWrite(buzzer,0);
      delay(1000);
    }
  	}
  	delay(500);
	}
 

Usage

  -Connect the components as per the circuit diagram.

  -Upload the code to your Arduino board.

  -Open the serial monitor to see the distance readings.

The buzzer and LED will react based on the proximity of objects.

License

This project is open-source. Feel free to modify and improve it!

