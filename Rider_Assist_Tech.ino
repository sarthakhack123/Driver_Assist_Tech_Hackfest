#include "angle_calc.h"

void setup() {
Serial.begin(9600);  
setup_angle_calc();
}

void loop() {
  loop_angle_calc();
}
