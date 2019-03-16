#include "Arduino.h"
#include "I2Cdev.h"
#include "MPU6050.h"

#define GYROSCOPE_SENSITIVITY 65.536
 
#define M_PI 3.14159265359      
 
#define dt 0.01  // 10 ms sample rate!    

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

#define OUTPUT_READABLE_ACCELGYRO

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

float angle_y=0;

void setup_angle_calc(void){
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
   
}

void complemetary_filter(short gy, short ax, short ay, short az,float *angle_y){
//   *angle_x += (gx / GYROSCOPE_SENSITIVITY) * dt;
   *angle_y += (gy / GYROSCOPE_SENSITIVITY) * dt;
   
   int forceMagnitudeApprox = abs(ax)+abs(ay)+abs(az);
   
   if (forceMagnitudeApprox > 8192 && forceMagnitudeApprox < 32768)
    {   
//        rollAcc_x, 
//        rollAcc_x = atan2f(ay, az) * 180 / M_PI;
//        *angle_x = (*angle_x) * 0.98 + rollAcc_x * 0.02;
        float rollAcc_y;        
        rollAcc_y = atan2f(ax, az) * 180 / M_PI;
        *angle_y = (*angle_y) * 0.98 + rollAcc_y * 0.02;
    }
    }


void loop_angle_calc(void){
  // put your main code here, to run repeatedly:
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  complemetary_filter(gy,ax, ay, az,&angle_y);
  Serial.println(angle_y);
}
