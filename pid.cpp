#include "Arduino.h"

float Kp = 7;    
float Ki = 6;        
float Kd = 3;        
float last_angle=0;
//float iTerm=0;
float pTerm, dTerm;          
float targetAngle = 0;          
 
double thisTime = 0;
double lastTime = 0;

int fly_wheel_pin1=9, fly_wheel_pin2=10;

void setup_pid(){
  pinMode(fly_wheel_pin1, OUTPUT);
  pinMode(fly_wheel_pin2, OUTPUT);
}
 
int PID_controller(float current_angle) {  
    thisTime = millis();
    double timeChange = double(thisTime - lastTime); //time since called last time
 
    // Error Signal
    float error = targetAngle - current_angle;
 
    pTerm  = Kp * error;
//    iTerm += Ki * error * timeChange;
    dTerm  = Kd * (current_angle - last_angle) / timeChange; 
 
    last_angle = current_angle; //Reasigning values
    lastTime = thisTime; //Reasigning values
 
//    float PIDValue = pTerm + iTerm - dTerm; //final output of controller
     float PIDValue = pTerm - dTerm; //final output of controller

    // Limits PID to max motor speed
    if (PIDValue > 255) 
        PIDValue = 255;
    else if (PIDValue < -255) 
        PIDValue = -255; 
   
    //Serial.print("pid value\t");
   
    
    return int(PIDValue);
}



void rotate(int motorinput){

  Serial.println(motorinput);
//  analogWrite(fly_wheel_pin1, motorinput);
 
  if (motorinput<0)
    {analogWrite(fly_wheel_pin1, abs(motorinput));
     analogWrite(fly_wheel_pin2,0);}
  else
    {analogWrite(fly_wheel_pin2, abs(motorinput));
     analogWrite(fly_wheel_pin1,0);}
}
