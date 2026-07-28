/*
  ESP32 Gesture Controlled Robotic Arm

  Controller:
  ESP32

  Communication:
  HC-05 Bluetooth UART

  Servo Driver:
  PCA9685

  Servo Mapping:

  CH0 -> Base Rotation
  CH1 -> Left Shoulder
  CH2 -> Right Shoulder
  CH3 -> Elbow
  CH4 -> Gripper

  Data Format:
  Base,Gripper,Elbow,Shoulder

*/


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);


// PCA9685 Channels

#define BASE_SERVO        0
#define LEFT_SHOULDER     1
#define RIGHT_SHOULDER    2
#define ELBOW             3
#define GRIPPER           4



// Servo pulse range

#define SERVO_MIN 150
#define SERVO_MAX 600



String data = "";


// Convert angle to PWM

int angleToPulse(int angle)
{
  return map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
}



// Servo movement function

void moveServo(int channel, int angle)
{
  angle = constrain(angle, 0, 180);

  int pulse = angleToPulse(angle);

  pwm.setPWM(channel, 0, pulse);
}



void setup()
{

  // HC-05 communication

  Serial.begin(9600);


  // ESP32 I2C

  Wire.begin(21,22);


  // Start PCA9685

  pwm.begin();

  pwm.setPWMFreq(50);


  delay(1000);



  // Initial servo position

  moveServo(BASE_SERVO,90);

  moveServo(LEFT_SHOULDER,90);

  moveServo(RIGHT_SHOULDER,90);

  moveServo(ELBOW,90);

  moveServo(GRIPPER,90);

}



void loop()
{


  while(Serial.available())
  {

    char c = Serial.read();


    if(c == '\n')
    {

      processData(data);

      data = "";

    }
    else
    {

      data += c;

    }

  }

}




void processData(String received)
{

  /*
     Received format:

     Base,Gripper,Elbow,Shoulder

     Example:

     90,120,60,80
  */


  int values[4];

  int index = 0;


  char buffer[50];

  received.toCharArray(buffer,50);



  char *token = strtok(buffer,",");



  while(token != NULL && index < 4)
  {

    values[index] = atoi(token);

    index++;

    token = strtok(NULL,",");

  }



  if(index == 4)
  {


    int baseAngle = values[0];

    int gripperAngle = values[1];

    int elbowAngle = values[2];

    int shoulderAngle = values[3];



    // Base rotation

    moveServo(BASE_SERVO, baseAngle);



    // Shoulder movement
    // Both shoulder servos are mechanically opposite

    moveServo(LEFT_SHOULDER, shoulderAngle);

    moveServo(RIGHT_SHOULDER, 180 - shoulderAngle);



    // Elbow

    moveServo(ELBOW, elbowAngle);



    // Gripper

    moveServo(GRIPPER, gripperAngle);


  }

}
