#include "angle_calc.h"
#include "pid.h"
#include "all_reciever.h"

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
