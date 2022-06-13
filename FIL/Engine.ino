
// Common commands

void speedStandard() // Start engines, set speed to 250
{
  analogWrite(enA, 250); // Sets motor A to speed 200 between 0-255
  analogWrite(enB, 250); // Sets motor B to speed 200 between 0-255
}

void speedOff() // Turn off engines
{
  digitalWrite(in1, LOW); // Turn off motor A
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); // Turn off motor B
  digitalWrite(in4, LOW);
  delay(1000);
}

void turnoff()
{
  digitalWrite(in1, LOW); // Turn off motor A
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); // Turn off motor B
  digitalWrite(in4, LOW);
}

void forward() // Set both engines to go forward
{
  digitalWrite(in1, LOW); // Sets motor A to go forward
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); // Sets motor B to go forward
  digitalWrite(in4, LOW);
}

void backward() // Set both engines to go forward
{
  digitalWrite(in1, HIGH); // Sets motor A to go forward
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); // Sets motor B to go forward
  digitalWrite(in4, LOW);
  delay(1700);
}

void turnA() // Turn in direction of motor A //left
{
  digitalWrite(in1, HIGH); // Sets motor A to go backwards
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); // Sets motor B to go forward
  digitalWrite(in4, LOW);
}

void turnB() // Turn in direction of motor B //Right
{
  digitalWrite(in1, LOW); // Sets motor A to go forwards
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); // Sets motor B to go backwards
  digitalWrite(in4, HIGH);
}

void calibrateTurn() // Calibrate in direction of motor A
{
  analogWrite(enA, 255); // Sets motor A to speed 200 between 0-255
  analogWrite(enB, 255); // Sets motor B to speed 200 between 0-255 
}

void calibrateStandard() // Calibrate in direction of motor B
{
  analogWrite(enA, 255); // Sets motor A to speed 200 between 0-255
  analogWrite(enB, 255); // Sets motor B to speed 200 between 0-255 
}

void calibrateB() // Calibrate in direction of motor B
{
  analogWrite(enA, 225); // Sets motor A to speed 200 between 0-255 //205
  analogWrite(enB, 255); // Sets motor B to speed 200 between 0-255  //200
}

void calibrateA() // Calibrate in direction of motor A
{
  analogWrite(enA, 235); // Sets motor A to speed 200 between 0-255
  analogWrite(enB, 255); // Sets motor B to speed 200 between 0-255 
}
