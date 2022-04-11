
// Motor A
int enA = 7;
int in1 = 6;
int in2 = 5;

// Motor B
int enB = 2;
int in3 = 4;
int in4 = 3;

void setup_engine() // Set all motor pins as outputs
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}



void engineDemo()
{
  digitalWrite(in1, HIGH); // Sets motor A to go forward
  digitalWrite(in2, LOW);
  analogWrite(enA, 250); // Sets motor A to speed 200 between 0-255

  digitalWrite(in3, HIGH); // Sets motor B to go forward
  digitalWrite(in4, LOW);
  analogWrite(enB, 250); // Sets motor B to speed 200 between 0-255

  delay(5000); // Delay 5 sec

  digitalWrite(in1, LOW); // Sets motor A to go backwards
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW); // Sets motor B to go backwards
  digitalWrite(in4, HIGH);

  delay(2000); // Delay 2 sec

  digitalWrite(in1, LOW); // Turn off motor A
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW); // Turn off motor B
  digitalWrite(in4, LOW);

  delay(2000); // Delay 2 sec
} 







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
}

void forward() // Set both engines to go forward
{
  digitalWrite(in1, HIGH); // Sets motor A to go forward
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); // Sets motor B to go forward
  digitalWrite(in4, LOW);
}

void turnA() // Turn in direction of motor A
{
  digitalWrite(in1, LOW); // Sets motor A to go backwards
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); // Sets motor B to go forward
  digitalWrite(in4, LOW);
}

void turnB() // Turn in direction of motor B
{
  digitalWrite(in1, HIGH); // Sets motor A to go forwards
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); // Sets motor B to go backwards
  digitalWrite(in4, HIGH);
}

void calibrateA() // Calibrate in direction of motor A
{
  analogWrite(enA, 245); // Sets motor A to speed 200 between 0-255
  analogWrite(enB, 255); // Sets motor B to speed 200 between 0-255
}

void calibrateB() // Calibrate in direction of motor B
{
  analogWrite(enA, 255); // Sets motor A to speed 200 between 0-255
  analogWrite(enB, 245); // Sets motor B to speed 200 between 0-255
}
