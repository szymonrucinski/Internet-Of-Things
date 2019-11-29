#include <ZumoShield.h>
#include <Wire.h>
#include <L3G.h>

#define LED_PIN 13
ZumoMotors motors;
#include "TurnSensor.h"
L3G gyro;

int32_t getAngle() 
{
  return (((int32_t)turnAngle >> 16) * 360) >> 16;
}

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
 turnSensorSetup();
  delay(500);
  turnSensorReset();
}

void loop() 
{

  int speed =100;
  motors.setLeftSpeed(speed);
  motors.setRightSpeed(speed);
  turnSensorUpdate();
  int32_t angle = getAngle();
  Serial.println(angle);

  //left +
  //right -
  
  if(angle>0)
  {
      motors.setLeftSpeed(180);
      Serial.println("Right rotation");
      //delay(1);
  }

    if(angle<0)
  {         
          motors.setRightSpeed(180);  
          Serial.println("Left rotation");
           //delay(1);

  }
  
    angle = getAngle();
  Serial.println(angle);
}

  
