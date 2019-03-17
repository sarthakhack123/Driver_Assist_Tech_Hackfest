#include "angle_calc.h"
#include "pid.h"

void setup() {
  Serial.begin(9600);
  setup_angle_calc();
  setup_pid();
}

void loop() {
  float tilt_angle;
  int motorinput;
  tilt_angle = loop_angle_calc();
  motorinput = PID_controller(tilt_angle);
  rotate(motorinput);
  timekeeper();
}
