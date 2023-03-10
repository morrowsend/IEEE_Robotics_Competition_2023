// Distance sensor (SENDER)
/*
 * Written by Keanu Ammons and John Clay
 * 
This code is for the "Sender Arduino". In breif, this code will send signals
to the reciever arduino, which will then control a set of stepper motors for
rover movement.


*/

// right distnace sensor
const int trigPin1 = 2;
const int echoPin1 = 3;

// middle distance sensor
const int trigPin2 = 4;
const int echoPin2 = 5;

// left distance sensor
const int trigPin3 = 6;
const int echoPin3 = 7;

// Defines other variables
long duration;
int distance1 = 0; 
int distance2 = 0;
int distance3 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin1,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(trigPin3,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(echoPin2,INPUT);
  pinMode(echoPin3,INPUT);

  // initalize serial monitor
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  distance3 = distance_sensor(trigPin3, echoPin3);
  distance2 = distance_sensor(trigPin2, echoPin2);
  distance1 = distance_sensor(trigPin1, echoPin1);
  delay(300);

  Serial1.print("A");
  Serial1.print(distance1);
  Serial1.print("B");
  Serial1.print(distance2);
  Serial1.print("C");
  Serial1.print(distance3);
  Serial1.println();
}

// function for distnace sensors
float distance_sensor(const int triggerPin, const int echoPin){
  /*

  Note: if distance is under 2 cm, the distnace sensor will incorrectly read
  values over 1000.

  */

  // define user values
  float distance;

  // define internal function variables
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  // Reads the echo pin, and returns the sound wave travel time in microseconds
  distance = 0.034 / 2 * pulseIn(echoPin, HIGH);
  return distance;
}
