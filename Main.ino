// master
// Written by Keanu J. Ammons and John Clay

// Include files
#include <Servo.h>

// Plow parameters
Servo servo1;
Servo servo2;

// Back Motor Connections
int Back_Left_Motor_Enable = 2;
int Back_Right_Motor_Enable = Back_Left_Motor_Enable;
int Back_Left_Motor_S1 = 26;
int Back_Left_Motor_S2 = 28;
int Back_Right_Motor_S1 = 24;
int Back_Right_Motor_S2 = 22;

// Front Motor Connections
int Front_Left_Motor_Enable = 3;
int Front_Right_Motor_Enable = Front_Left_Motor_Enable;
int Front_Left_Motor_S1 = 34; 
int Front_Left_Motor_S2 = 36;
int Front_Right_Motor_S1 = 40;
int Front_Right_Motor_S2 = 38;

// Message parameter
String message;

// Motion parameters

// Rotation parameters
int A_rotation_speed = 65;
int B_rotation_speed = 65;
float rotation_time_90 = 0.935;

// Linear motion parameters
int A_forward_speed = 65;
int B_forward_speed = 65;
float forward_time_1 = 0.677;

// Auto start feature
const int analogInPin = A0;
int sensorValue = 0; // value read
int outputValue = 0; // value read from PWM

// 10 and 5 are PWM
// 6 and 7 are output signals for motor B
// 8 and 9 are output signals for motor A

void setup() {
  
  // Set all the backward motor control pins to outputs
  pinMode(Back_Left_Motor_Enable, OUTPUT);
  pinMode(Back_Right_Motor_Enable, OUTPUT);
  pinMode(Back_Left_Motor_S1, OUTPUT);
  pinMode(Back_Left_Motor_S2, OUTPUT);
  pinMode(Back_Right_Motor_S1, OUTPUT);
  pinMode(Back_Right_Motor_S2, OUTPUT);

   // Set all the forward motor control pins to outputs
  pinMode(Front_Left_Motor_Enable, OUTPUT);
  pinMode(Front_Right_Motor_Enable, OUTPUT);
  pinMode(Front_Left_Motor_S1, OUTPUT);
  pinMode(Front_Left_Motor_S2, OUTPUT);
  pinMode(Front_Right_Motor_S1, OUTPUT);
  pinMode(Front_Right_Motor_S2, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(Back_Left_Motor_S1, LOW);
  digitalWrite(Back_Left_Motor_S2, LOW);
  digitalWrite(Back_Right_Motor_S1, LOW);
  digitalWrite(Back_Right_Motor_S2, LOW);
  digitalWrite(Front_Left_Motor_S1, LOW);
  digitalWrite(Front_Left_Motor_S2, LOW);
  digitalWrite(Front_Right_Motor_S1, LOW);
  digitalWrite(Front_Right_Motor_S2, LOW);

  // Servo motor parameters
  servo2.attach(9);
  servo1.attach(10);
  servo1.write(120); // reset position
  servo2.write(50);

  // initalize serial monitor
  Serial1.begin(9600);
  Serial.begin(9600);

  // Auto start functionality
  /*
    while(outputValue < 250){
    sensorValue = analogRead(analogInPin);
    outputValue = map(sensorValue, 0, 1023, 0, 255);
    delay(5);
    }
  */
}

void loop() {

  
  int Rear_Speed = 70;
  int Forward_Speed = 70;
  // RED SQUARE //
    delay(7000);
    forward(80,80,4);
    delay(20);
    forward(40,40,2); 
    delay(20);
    servo2.write(130); // Red chip bucket down
    delay(1000);
    servo2.write(50); // Red chip bucket up
  // GREEN SQUARE //
    delay(2000);
    Hard_Right(80,80,6.5); 
    delay(20);
    forward(40,40,2);
    servo1.write(30); // Green chip bucket down
    delay(1000);
    servo1.write(120); // Green chip bucket up
  // RECYCLING //
    delay(20);
  // LIGHT SWITCH //
    backward(80,80,7);
    delay(20);
    //get to light switch
    Hard_Left(85,85,3);
    delay(20);
    backward(40,40,2);
    delay(20);
    Hard_Right(80,80,4);
    delay(20);
    delay(1000);
}
