#include "angle_calc.h"
#include "pid.h"
#include "all_reciever.h"

#define STD_LOOP_TIME .01
unsigned long loopStartTime = 0;

void setup() {
  Serial.begin(9600);
  setup_angle_calc();
  setup_all_reciever();
  setup_pid();
}

void loop() {
  float tilt_angle;
  int motorinput;
  loop_all_reciever();
  tilt_angle = loop_angle_calc();
  motorinput = PID_controller(tilt_angle);
  rotate(motorinput);
  timekeeper();
}

void timekeeper() {
    float timeGoneBy = millis() - loopStartTime; // Calculate time since loop began
    // required time not reached!
    if (timeGoneBy < STD_LOOP_TIME) 
        delay(STD_LOOP_TIME - timeGoneBy);
    //Serial.println("timekeeper chl rha");         //debugging
    loopStartTime = millis(); //Update loop timer variables   
}
