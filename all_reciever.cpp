//#define interrupt A0;
//#define interrupt2 A1;

#include "Arduino.h"

int m1=5,m2=6;
int flyw1=9,flyw2=10;

void setup_all_reciever(){
    pinMode(m1,OUTPUT);
    pinMode(m2,OUTPUT);
    pinMode(flyw1,OUTPUT);
    pinMode(flyw2,OUTPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
}

//int maxm=0, minm=1500;

void motor(int pwm, int ms, int dir){
  if(abs(pwm) > 20){
// For the High Torque motor
//    if (ms == 1){
//      switch(dir){
//        case 1: analogWrite(flyw2, abs(pwm));
//                digitalWrite(flyw1, 0);
//                break;
//        case 2: analogWrite(flyw1, abs(pwm));
//                digitalWrite(flyw2, 0);
//                break;
//      }
//    }
    if (ms == 2){
      switch(dir){
        case 1: analogWrite(m2, abs(pwm));
                digitalWrite(m1, 0);
                break;
        case 2: analogWrite(m1, abs(pwm));
                digitalWrite(m2, 0);
                break;
      }
    }
  }
  else{
// For the High Torque motor
//    if (ms == 1){  
//      digitalWrite(flyw1, 0);
//      digitalWrite(flyw2, 0);
//      }
    if (ms == 2){
      digitalWrite(m1, 0);
      digitalWrite(m2, 0);
      }
  }
}

void loop_all_reciever(){

  int temp2 = pulseIn(A0, HIGH);
//  int temp = pulseIn(A1, HIGH);
//  Serial.print("Roll: ");
//Serial.print(temp);
//  Serial.print("\tForward: ");
//  Serial.println(temp2);
  int pwm1, pwm2;
  
//input out of bounds exception
// For the High Torque motor
//  if(temp>2000)
//  temp = 2000;
//  else if(temp<1000)
//  temp = 1000;

//For the driving wheel
  if(temp2>2000)
  temp2 = 2000;
  else if(temp2<1000)
  temp2 = 1000;

  
//Uncomment for High Torque Motor
//  pwm1 = map(temp,1000,2000,-255,255);
  pwm2 = map(temp2,1000,2000,-255,255);
  
//output
//Uncomment for High Torque Motor
//  if(pwm1<0)
//  motor(pwm1,1,2);
//  else 
//  motor(pwm1,1,1);
  
  if(pwm2<0)
  motor(pwm2,2,2);
  else 
  motor(pwm2,2,1);
  
}
//Uncomment to get min and max reading from rc stick
//  if(maxm<temp)
//  maxm = temp;
//  if(minm>temp)
//  minm = temp;
//  Serial.print("Read = ");
//  Serial.print(temp);
//  Serial.print("\tMax = ");
//  Serial.print(maxm);
//  Serial.print("\tMin = ");
//  Serial.println(minm);

//Complementary Filter Algo
//  gyro_roll_input = (gyro_roll_input * 0.7) + ((gyro_roll / 65.5) * 0.3);   //Gyro pid input is deg/sec.
//  gyro_pitch_input = (gyro_pitch_input * 0.7) + ((gyro_pitch / 65.5) * 0.3);//Gyro pid input is deg/sec.
//  gyro_yaw_input = (gyro_yaw_input * 0.7) + ((gyro_yaw / 65.5) * 0.3);      //Gyro pid input is deg/sec.
