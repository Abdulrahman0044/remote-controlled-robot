/*
  #################pragma endregion
  Project: BB-8-inspired Robot
  Written by: Abdulrahman Abdulrahman
*/

#include <RemoteXY.h>
#include <Servo.h>
// RemoteXY configuration
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,9,0,0,0,22,0,8,25,0,
  2,0,10,11,6,28,79,66,83,84,
  65,67,76,69,95,65,80,73,0,79,
  70,70,0,70,79,82,87,65,82,68,
  95,83,80,69,69,68,0 };
// this structure defines all the variables and events of your control interface
struct {
  // input variable
  uint8_t joystick_x; // =0..255 x coordinate of joystick
  uint8_t joystick_y; // =0..255 y coordinate of joystick
  // output variable
  uint8_t servo_angle; // =0..180 servo angle
  // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0
  // uint8_t unused[0];
} RemoteXY;
#pragma pack(pop)

#define SERVO_PIN 6
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define LEFT_MOTOR_PIN1 2
#define LEFT_MOTOR_PIN2 3
#define RIGHT_MOTOR_PIN1 4
#define RIGHT_MOTOR_PIN2 5

Servo servoMotor;

void setup()
{
  RemoteXY_Init();
  servoMotor.attach(SERVO_PIN);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
}

void loop()
{
  RemoteXY_Handler();
  // control servo with joystick
  int servoAngle = map(RemoteXY.joystick_x, 0, 255, 0, 180);
  servoMotor.write(servoAngle);
  
  // perform obstacle avoidance
  int distance = getDistance();
  if (distance < 20) { // Adjust this threshold according to your needs
    // Stop motors and change direction
    stopMotors();
    if (distance > 10) {
      // Turn right
      digitalWrite(LEFT_MOTOR_PIN1, HIGH);
      digitalWrite(LEFT_MOTOR_PIN2, LOW);
      digitalWrite(RIGHT_MOTOR_PIN1, LOW);
      digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
    } else {
      // Turn left
      digitalWrite(LEFT_MOTOR_PIN1, LOW);
      digitalWrite(LEFT_MOTOR_PIN2, HIGH);
      digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
      digitalWrite(RIGHT_MOTOR_PIN2, LOW);
    }
  } else {
    // Continue moving forward
    digitalWrite(LEFT_MOTOR_PIN1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);
    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
  }
}

int getDistance() {
  // Send ultrasonic pulse
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Measure the response time of ultrasonic sensor
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert response time into distance
  int distance = duration * 0.034 / 2;

  return distance;
}

void stopMotors() {
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

