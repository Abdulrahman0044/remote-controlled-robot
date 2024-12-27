# Remote-Controlled Obstacle-Avoiding Robot

This project implements a remote-controlled robot capable of obstacle avoidance. It utilizes the **RemoteXY** library for remote control via a mobile app and features servo motor control and ultrasonic sensors for obstacle detection.

## Features
- **Joystick Control**: A mobile app joystick controls the robot's movements and the servo motor angle.
- **Obstacle Avoidance**: The robot uses an ultrasonic sensor to detect obstacles and avoid collisions by stopping or changing direction.
- **Servo Motor**: Dynamically adjusts the servo motor angle based on joystick input.

---

## Components Required
1. **Arduino Board** (e.g., Uno, Mega, etc.)
2. **Servo Motor**
3. **Ultrasonic Sensor** (e.g., HC-SR04)
4. **L298N Motor Driver** (or equivalent for controlling motors)
5. **DC Motors** and Wheels
6. **Power Supply**
7. **RemoteXY App** (for control interface)

---

## Pin Configuration
| Component         | Pin Name         | Arduino Pin |
|--------------------|------------------|-------------|
| Servo Motor        | `SERVO_PIN`      | 6           |
| Ultrasonic Trigger | `TRIGGER_PIN`    | 9           |
| Ultrasonic Echo    | `ECHO_PIN`       | 10          |
| Left Motor Input 1 | `LEFT_MOTOR_PIN1`| 2           |
| Left Motor Input 2 | `LEFT_MOTOR_PIN2`| 3           |
| Right Motor Input 1| `RIGHT_MOTOR_PIN1`| 4           |
| Right Motor Input 2| `RIGHT_MOTOR_PIN2`| 5           |

---

## RemoteXY Interface Configuration
The **RemoteXY** library is used for creating a simple graphical interface. 

### Interface Design:
- **Joystick**: Controls the servo angle and robot movement.
- **Status Indicators**: Display connection status and forward speed.

### Configuration Code:
```cpp
uint8_t RemoteXY_CONF[] =
  { 255,9,0,0,0,22,0,8,25,0,
  2,0,10,11,6,28,79,66,83,84,
  65,67,76,69,95,65,80,73,0,79,
  70,70,0,70,79,82,87,65,82,68,
  95,83,80,69,69,68,0 };
```

## Setup
### Hardware Connection:
- Connect components as per the pin configuration.
- Ensure proper power supply to the Arduino, motors, and sensors.

### Software Installation:
- Install the ```RemoteXY``` library via the Arduino IDE library manager.
- Upload the code to your Arduino board.

### Mobile App:
- Download and install the RemoteXY app on your smartphone.
- Use the configuration code to set up the interface in the app.

