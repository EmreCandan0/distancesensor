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
  Serial.print("Mesafe = ");
    if (distance >= 400 || distance <= 2) 
  {
    Serial.println("Out of range");
  }

  else 
  {
    Serial.print(distance);
    Serial.println(" cm");

   if(distance<10){
      digitalWrite(LEDS,HIGH);
      analogWrite(buzzer,1000);
      delay(1000);
    }
   else if(distance<30){
    digitalWrite(LEDS,LOW);
      analogWrite(buzzer,1000);
      delay(50);
      analogWrite(buzzer,0);
      delay(50);
    }
    else if(distance<50){
      digitalWrite(LEDS,LOW);
      analogWrite(buzzer,1000);
      delay(100);
      analogWrite(buzzer,0);
      delay(100); 
    }

    else if(distance<100){
      digitalWrite(LEDS,LOW);
      analogWrite(buzzer,1000);
      delay(100);
      analogWrite(buzzer,0);
      delay(1000);
      }
    
    
  
  }
  delay(500);

}
