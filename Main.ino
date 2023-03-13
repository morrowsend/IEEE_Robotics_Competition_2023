// master
// Written by Keanu J. Ammons and John Clay

// Include files
#include <Servo.h>
// Plow parameters
Servo myservo1;
Servo myservo2;
// Motor A connections
int enA = 5;
int in1 = 4;
int in2 = 7;
// Motor B connections
int in3 = 11;
int in4 = 9;
int enB = 10;
// Message parameters
String message;
// Motion parameters
 // Rotation parameters
 int A_rotation_speed = 65;
 int B_rotation_speed = 65;
 float rotation_time_90 = 0.96;
 // Linear motion parameters
 int A_forward_speed = 65;
 int B_forward_speed = 65;
 float forward_time_1 = 0.677;


// 10 and 5 are PWM
// 6 and 7 are output signals for motor B
// 8 and 9 are output signals for motor A 

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Servo motor parameters
  myservo1.attach(12);
  myservo2.attach(13);

  // initalize serial monitor
  Serial1.begin(9600);
  Serial.begin(9600);

}

void loop() {

  /*
  // basic test code
  forward(150,150,1.5);
  delay(2000);
  backward(150,150,1.5);
  delay(2000);
  */
  
  // Servo motor commands

  // Push the plow  down
  /*
  myservo1.write(90);
  myservo2.write(90);
  delay(4000);
  */
 
   
  message = Serial1.readString();
  //if(message){
  //  Serial.println(message);
  //}
  // allocate a dynmaic memory heap for each character array
  int max_mem = 4;
  int length = message.length();
  char* sensor1 = (char*)malloc(max_mem * sizeof(char));
  char* sensor2 = (char*)malloc(max_mem * sizeof(char));
  char* sensor3 = (char*)malloc(max_mem * sizeof(char));

  // search through the message to identify letters and numbers
  for (int i = 0; i < message.length(); i++) {
    // check and see if letter A was found
    if (message[i] == 'A') {

      int j = 1;
      int k = 0;
      // while there is a digit, store the digit in heap memory.
      while (isdigit(message[i + j])) {
        sensor1[k] = message[i + j];
        j++;
        k++;
      }
      i = i + j;
    }
    // check to see if letter B was found
    if (message[i] == 'B') {

      int j = 1;
      int k = 0;
      // while there is a digit, store the digit in heap memory.
      while (isdigit(message[i + j])) {
        sensor2[k] = message[i + j];
        j++;
        k++;
      }
      i = i + j;
    }
    // check to see if letter C was found
    if (message[i] == 'C') {

      int j = 1;
      int k = 0;
      // while there is a digit, store the digit in heap memory.
      while (isdigit(message[i + j])) {
        sensor3[k] = message[i + j];
        j++;
        k++;
      }
      i = i + j;
    }
  }

  // convert characters into a number
  int B_sensor_2 = atoi(sensor1); // This is left
  int A_sensor_1 = atoi(sensor2); // This is the front
  int C_sensor_3 = atoi(sensor3); // This is right
  // Serial.println(A_sensor_1);

  // Auto Code
   forward(A_forward_speed,B_forward_speed,forward_time_1*2);
   delay(500);
   clockwise(A_rotation_speed,B_rotation_speed,rotation_time_90);
   delay(20);
   
    while (A_sensor_1 > 10 || B_sensor_2 > 10 || C_sensor_3 > 10) {
      forward(A_forward_speed,B_forward_speed,1);
      delay(20);
      if (A_sensor_1 < 5 || A_sensor_1 >= 1000){
        backward(A_forward_speed,B_forward_speed, 1);
        delay(20);
        clockwise(A_rotation_speed,B_rotation_speed,rotation_time_90);
        delay(500);
      }
      if (B_sensor_2 < 5 || B_sensor_2 > 1000){
        clockwise(A_rotation_speed,B_rotation_speed,0.2);
        delay(500);
      }
      if (C_sensor_3 < 5 || C_sensor_3 > 1000){
        counterClockwise(A_rotation_speed,B_rotation_speed,0.2);
        delay(500);
      }
      if ( (A_sensor_1 < 5 || A_sensor_1 > 1000)&&(B_sensor_2 < 5 || B_sensor_2 > 1000) ){
        backward(A_forward_speed,B_forward_speed, 1);
        delay(20);
        clockwise(A_rotation_speed,B_rotation_speed,rotation_time_90);
        delay(500);
      }
      if ( (A_sensor_1 < 10 || A_sensor_1 > 1000)&&(C_sensor_3 < 10 || C_sensor_3 > 1000) ){
        backward(A_forward_speed,B_forward_speed, 1);
        delay(20);
        counterClockwise(A_rotation_speed,B_rotation_speed,rotation_time_90);
        delay(500);
      }
    }

  // free allocated memory heap to save space on the hard drive
  free(sensor1);
  free(sensor2);
  free(sensor3);
   
}
   
