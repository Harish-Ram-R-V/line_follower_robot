// Pin definitions
const int leftSensorPin = A0;
const int rightSensorPin = A1;

const int leftMotorPWM = 5;
const int leftMotorIn1 = 2;
const int leftMotorIn2 = 3;

const int rightMotorPWM = 6;
const int rightMotorIn3 = 4;
const int rightMotorIn4 = 7;

// PID parameters
float Kp = 0.8;
float Ki = 0.0;
float Kd = 0.1;

float previousError = 0;
float integral = 0;

int baseSpeed = 150;

void setup() {
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  pinMode(leftMotorPWM, OUTPUT);
  pinMode(leftMotorIn1, OUTPUT);
  pinMode(leftMotorIn2, OUTPUT);

  pinMode(rightMotorPWM, OUTPUT);
  pinMode(rightMotorIn3, OUTPUT);
  pinMode(rightMotorIn4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int leftSensorValue = analogRead(leftSensorPin);
  int rightSensorValue = analogRead(rightSensorPin);

  // Normalize sensor readings (assuming line is black = low value)
  int leftValue = map(leftSensorValue, 0, 1023, 0, 100);
  int rightValue = map(rightSensorValue, 0, 1023, 0, 100);

  // Calculate error: left sensor - right sensor (range -100 to 100)
  int error = leftValue - rightValue;

  // PID calculations
  integral += error;
  float derivative = error - previousError;
  float output = Kp * error + Ki * integral + Kd * derivative;

  previousError = error;

  // Calculate motor speeds
  int leftMotorSpeed = baseSpeed + output;
  int rightMotorSpeed = baseSpeed - output;

  // Constrain motor speeds to PWM limits
  leftMotorSpeed = constrain(leftMotorSpeed, 0, 255);
  rightMotorSpeed = constrain(rightMotorSpeed, 0, 255);

  // Drive motors
  driveMotor(leftMotorIn1, leftMotorIn2, leftMotorPWM, leftMotorSpeed);
  driveMotor(rightMotorIn3, rightMotorIn4, rightMotorPWM, rightMotorSpeed);

  // Debugging output
  Serial.print("L Sensor: "); Serial.print(leftSensorValue);
  Serial.print(" | R Sensor: "); Serial.print(rightSensorValue);
  Serial.print(" | Error: "); Serial.print(error);
  Serial.print(" | Output: "); Serial.println(output);

  delay(10);
}

void driveMotor(int pin1, int pin2, int pwmPin, int speed) {
  if (speed >= 0) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    analogWrite(pwmPin, speed);
  } else {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    analogWrite(pwmPin, -speed);
  }
}
