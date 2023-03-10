void testServo(){

  myservo1.write(90);
  myservo2.write(90);
  delay(4000);

  // Push the plow back down
  myservo1.write(0);
  myservo2.write(0);
  delay(4000);
  
}

void pause(int seconds){

  // turn the motor speed to zero
  analogWrite(enA, 0);
  analogWrite(enB, 0);

  // turn the motors off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // delay for a certain number of seconds.
  delayMicroseconds(seconds*1000);

}

// This causes the motors to go forward
void backward(int motor_speed_1, int motor_speed_2, float delayTime){

  // variables
  int x;
  int seconds;

  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, motor_speed_1);
  analogWrite(enB, motor_speed_2);

  // Turn on motors (do not change)
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(20);

  // delay time
  x = delayTime*1000;
  seconds = ceil(x);
  delay(seconds);

  // turn the motors off briefly
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(20);
  
}

// This causes the rover to turn counter-clockwise
void counterClockwise(int motor_speed_1, int motor_speed_2){

  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, motor_speed_1);
  analogWrite(enB, motor_speed_2);

  // Turn the motors clockwise
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

   delay(2000);
  
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// This causes the rover to turn clockwise
void clockwise(int motor_speed_1, int motor_speed_2){
  
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, motor_speed_1);
  analogWrite(enB, motor_speed_2);
  
  // Now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);
  
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void forward(int motor_speed_1, int motor_speed_2, float delayTime){

  // variables
  int x;
  int seconds;
  
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, motor_speed_1);
  analogWrite(enB, motor_speed_2);
  
  // reverse the direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(20);
   
  // delay time
  x = delayTime*1000;
  seconds = ceil(x);
  delay(seconds);
  
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(20);
}