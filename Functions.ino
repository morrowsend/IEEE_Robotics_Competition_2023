
void pause(float delayTime){

  // variables
  int x;
  int seconds;

  // turn the motor speed to zero
  analogWrite(Back_Left_Motor_Enable, 0);
  analogWrite(Back_Right_Motor_Enable, 0);
  analogWrite(Front_Left_Motor_Enable, 0);
  analogWrite(Front_Right_Motor_Enable, 0);

  // turn the motors off
  digitalWrite(Front_Left_Motor_S1, LOW);
  digitalWrite(Front_Left_Motor_S2, LOW);
  digitalWrite(Front_Right_Motor_S1, LOW);
  digitalWrite(Front_Right_Motor_S2, LOW);
  digitalWrite(Back_Left_Motor_S1, LOW);
  digitalWrite(Back_Left_Motor_S2, LOW);
  digitalWrite(Back_Right_Motor_S1, LOW);
  digitalWrite(Back_Right_Motor_S2, LOW);

  // delay time
  x = delayTime*1000;
  seconds = ceil(x);
  delay(seconds);
}

// This causes the motors to go forward
void backward(int Rear_Speed, int Forward_Speed, float delayTime){

  // variables
  int x;
  int seconds;

  // For PWM maximum possible values are 0 to 255
  analogWrite(Back_Left_Motor_Enable, Rear_Speed);
  analogWrite(Back_Right_Motor_Enable, Rear_Speed);
  analogWrite(Front_Left_Motor_Enable, Forward_Speed);
  analogWrite(Front_Right_Motor_Enable, Forward_Speed);
  
  // Move motors forward
  digitalWrite(Back_Left_Motor_S1, HIGH);
  digitalWrite(Back_Left_Motor_S2, LOW);
  digitalWrite(Back_Right_Motor_S1, LOW);
  digitalWrite(Back_Right_Motor_S2, HIGH);
  digitalWrite(Front_Left_Motor_S1, LOW);
  digitalWrite(Front_Left_Motor_S2, HIGH);
  digitalWrite(Front_Right_Motor_S1, HIGH);
  digitalWrite(Front_Right_Motor_S2, LOW);

  delay(20);

  // delay time
  x = delayTime*1000;
  seconds = ceil(x);
  delay(seconds);

  // turn the motors off briefly
  digitalWrite(Front_Left_Motor_S1, LOW);
  digitalWrite(Front_Left_Motor_S2, LOW);
  digitalWrite(Front_Right_Motor_S1, LOW);
  digitalWrite(Front_Right_Motor_S2, LOW);
  digitalWrite(Back_Left_Motor_S1, LOW);
  digitalWrite(Back_Left_Motor_S2, LOW);
  digitalWrite(Back_Right_Motor_S1, LOW);
  digitalWrite(Back_Right_Motor_S2, LOW);

  delay(20);
  
}

// This causes the rover to make a hard left
void Hard_Left(int Rear_Speed, int Forward_Speed, float delayTime){

  // variables
  int x;
  int seconds;

  // For PWM maximum possible values are 0 to 255
  analogWrite(Back_Left_Motor_Enable, Rear_Speed);
  analogWrite(Back_Right_Motor_Enable, Rear_Speed);
  analogWrite(Front_Left_Motor_Enable, Forward_Speed);
  analogWrite(Front_Right_Motor_Enable, Forward_Speed);

  // make the rover take a hard left
  digitalWrite(Front_Left_Motor_S1, LOW);
  digitalWrite(Front_Left_Motor_S2, HIGH);
  digitalWrite(Front_Right_Motor_S1, LOW);
  digitalWrite(Front_Right_Motor_S2, HIGH);
  digitalWrite(Back_Left_Motor_S1, LOW);
  digitalWrite(Back_Left_Motor_S2, HIGH);
  digitalWrite(Back_Right_Motor_S1, LOW);
  digitalWrite(Back_Right_Motor_S2, HIGH);
  
  delay(20);

  // delay time
  x = delayTime*1000;
  seconds = ceil(x);
  delay(seconds);

  // stop the rover
  digitalWrite(Front_Left_Motor_S1, LOW);
  digitalWrite(Front_Left_Motor_S2, LOW);
  digitalWrite(Front_Right_Motor_S1, LOW);
  digitalWrite(Front_Right_Motor_S2, LOW);
  digitalWrite(Back_Left_Motor_S1, LOW);
  digitalWrite(Back_Left_Motor_S2, LOW);
  digitalWrite(Back_Right_Motor_S1, LOW);
  digitalWrite(Back_Right_Motor_S2, LOW);

  delay(20);

}

// This causes the rover to turn clockwise
void Hard_Right(int Rear_Speed, int Forward_Speed, float delayTime){

  // variables
  int x;
  int seconds;

  // For PWM maximum possible values are 0 to 255
  analogWrite(Back_Left_Motor_Enable, Rear_Speed);
  analogWrite(Back_Right_Motor_Enable, Rear_Speed);
  analogWrite(Front_Left_Motor_Enable, Forward_Speed);
  analogWrite(Front_Right_Motor_Enable, Forward_Speed);

  // make the rover take a hard right
  digitalWrite(Front_Left_Motor_S1, HIGH);
  digitalWrite(Front_Left_Motor_S2, LOW);
  digitalWrite(Front_Right_Motor_S1, HIGH);
  digitalWrite(Front_Right_Motor_S2, LOW);
  digitalWrite(Back_Left_Motor_S1, HIGH);
  digitalWrite(Back_Left_Motor_S2, LOW);
  digitalWrite(Back_Right_Motor_S1, HIGH);
  digitalWrite(Back_Right_Motor_S2, LOW);
  
  delay(20);

  // delay time
  x = delayTime*1000;
  seconds = ceil(x);
  delay(seconds);

  // stop the rover
  digitalWrite(Front_Left_Motor_S1, LOW);
  digitalWrite(Front_Left_Motor_S2, LOW);
  digitalWrite(Front_Right_Motor_S1, LOW);
  digitalWrite(Front_Right_Motor_S2, LOW);
  digitalWrite(Back_Left_Motor_S1, LOW);
  digitalWrite(Back_Left_Motor_S2, LOW);
  digitalWrite(Back_Right_Motor_S1, LOW);
  digitalWrite(Back_Right_Motor_S2, LOW);

  delay(20);
  
}

void forward(int Rear_Speed, int Forward_Speed, float delayTime){

  // variables
  int x;
  int seconds;
  
  // For PWM maximum possible values are 0 to 255
  analogWrite(Back_Left_Motor_Enable, Rear_Speed);
  analogWrite(Back_Right_Motor_Enable, Rear_Speed);
  analogWrite(Front_Left_Motor_Enable, Forward_Speed);
  analogWrite(Front_Right_Motor_Enable, Forward_Speed);
  
  // reverse the direction
  digitalWrite(Back_Left_Motor_S1, LOW);
  digitalWrite(Back_Left_Motor_S2, HIGH);
  digitalWrite(Back_Right_Motor_S1, HIGH);
  digitalWrite(Back_Right_Motor_S2, LOW);
  digitalWrite(Front_Left_Motor_S1, HIGH);
  digitalWrite(Front_Left_Motor_S2, LOW);
  digitalWrite(Front_Right_Motor_S1, LOW);
  digitalWrite(Front_Right_Motor_S2, HIGH);

  delay(20);
   
  // delay time
  x = delayTime*1000;
  seconds = ceil(x);
  delay(seconds);
  
  // Turn off motors
  digitalWrite(Front_Left_Motor_S1, LOW);
  digitalWrite(Front_Left_Motor_S2, LOW);
  digitalWrite(Front_Right_Motor_S1, LOW);
  digitalWrite(Front_Right_Motor_S2, LOW);
  digitalWrite(Back_Left_Motor_S1, LOW);
  digitalWrite(Back_Left_Motor_S2, LOW);
  digitalWrite(Back_Right_Motor_S1, LOW);
  digitalWrite(Back_Right_Motor_S2, LOW);

  delay(20);
}



void full_Course(){

  int Rear_Speed = 70;
  int Forward_Speed = 70;
  // get to the red square
  delay(5000);
  forward(71,71,1.3);
  delay(20);
  forward(40,40,0.25); 
  //get to the green square
  delay(2000);
  Hard_Right(85,85,1.6);
  delay(20);
  Hard_Right(80,80,0.5);
  delay(20);
  forward(40,40,0.25);
  //go to recycling
  delay(2000);
  backward(85,85,5);
  delay(20);
  //get to light switch
  Hard_Left(85,85,1.0);
  delay(20);
  backward(40,40,1.0);
  delay(20);
  Hard_Left(80,80,1.0);
  delay(2000);
  
}
