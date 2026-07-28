/*
  ESP32 Gesture Controlled Robotic Arm
  Glove Controller Code

  Controller: Arduino Nano

  Sensors:
  MPU6050  -> Hand rotation
  Flex A0  -> Thumb (Gripper)
  Flex A1  -> Index (Elbow)
  Flex A2  -> Middle (Shoulder)

  Communication:
  HC-05 Bluetooth UART
*/

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;


// Flex sensor pins
#define THUMB_FLEX  A0
#define INDEX_FLEX  A1
#define MIDDLE_FLEX A2


// MPU values
int16_t ax, ay, az;
int16_t gx, gy, gz;


// Calibration values
int thumbValue;
int indexValue;
int middleValue;


// MPU angle
float angleX;
float angleY;


void setup()
{
  Serial.begin(9600);   // HC-05 Bluetooth communication

  Wire.begin();

  mpu.initialize();


  if(mpu.testConnection())
  {
    // Serial monitor disabled because HC-05 uses RX/TX
  }


  pinMode(THUMB_FLEX, INPUT);
  pinMode(INDEX_FLEX, INPUT);
  pinMode(MIDDLE_FLEX, INPUT);


  delay(1000);
}


void loop()
{

  // Read MPU6050 data

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);


  // Convert accelerometer values into angles

  angleX = atan2(ay, az) * 180 / PI;
  angleY = atan2(ax, az) * 180 / PI;



  // Read flex sensors

  thumbValue  = analogRead(THUMB_FLEX);
  indexValue  = analogRead(INDEX_FLEX);
  middleValue = analogRead(MIDDLE_FLEX);



  // Map flex values to servo angles

  int gripperAngle = map(thumbValue, 300, 900, 0, 180);

  int elbowAngle = map(indexValue, 300, 900, 0, 180);

  int shoulderAngle = map(middleValue, 300, 900, 0, 180);



  // Limit values

  gripperAngle = constrain(gripperAngle,0,180);
  elbowAngle = constrain(elbowAngle,0,180);
  shoulderAngle = constrain(shoulderAngle,0,180);



  /*
    Data format sent through Bluetooth:

    Base,Gripper,Elbow,Shoulder

    Example:
    90,120,45,80
  */


  Serial.print((int)angleX);
  Serial.print(",");

  Serial.print(gripperAngle);
  Serial.print(",");

  Serial.print(elbowAngle);
  Serial.print(",");

  Serial.println(shoulderAngle);



  delay(50);
}
