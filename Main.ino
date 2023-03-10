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
  myservo1.write(90);
  myservo2.write(90);
  delay(4000);
 
  if (Serial1.available()>0){
   
  message = Serial1.readString();
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
  int A_sensor_1 = atoi(sensor1);
  int B_sensor_2 = atoi(sensor2);
  int C_sensor_3 = atoi(sensor3);

  // free allocated memory heap to save space on the hard drive
  free(sensor1);
  free(sensor2);
  free(sensor3);
   
   }
   
}
