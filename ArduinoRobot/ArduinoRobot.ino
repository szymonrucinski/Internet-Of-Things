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

  int speed = 40;
  motors.setLeftSpeed(speed);
  motors.setRightSpeed(speed);
  turnSensorUpdate();
  int32_t angle = getAngle();
  Serial.println(angle);
  
  if(angle<0)
  {
          speed+=5;
      motors.setRightSpeed(speed);
      
  }
//   motors.setLeftSpeed(100);
//  motors.setRightSpeed(100);

    if(angle>0)
  {

                speed+=5;
          motors.setLeftSpeed(speed);
     
  }
// motors.setLeftSpeed(100);
//  motors.setRightSpeed(100);


}

  
  
//  digitalWrite(LED_PIN, HIGH);
//  int speed = 0;
//  for ( speed=0 ;speed <= 100; speed++)
//  {
//    motors.setLeftSpeed(speed);
//    motors.setRightSpeed(speed);
//  
//    turnSensorUpdate();
//  int32_t angle = getAngle();
//  Serial.println(angle);
//  
//  if(angle<0)
//  {
//    while(angle!=0)
//    {
//          speed+=2;
//      motors.setLeftSpeed(speed);
//      
//   }
//    
//   
//
//    if(angle>0)
//  {
//   
//                speed+=2;
//          motors.setRightSpeed(speed);
//     
//   }
//}
