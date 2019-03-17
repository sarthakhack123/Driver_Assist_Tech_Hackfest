s#ifndef ANGLE_CALC
  #define ANGLE_CALC

	void setup_angle_calc(void);

	float loop_angle_calc(void);

	void filter(short gy, short ax, short ay, short az,float *angle_y);

#endif
