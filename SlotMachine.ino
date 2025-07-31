#include <AFMotor.h>

AF_DCMotor motor1(3);
AF_DCMotor motor2(1);
AF_DCMotor motor3(4);
int Y_pin = A0;

void setup() {
  // Nothing needed here
}

void loop() {
  int y = analogRead(Y_pin);

  if (y < 400) {
    motor1.setSpeed(150);
    motor2.setSpeed(150);
    motor3.setSpeed(150);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);

    delay(5000);

    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);

    delay(500); // short pause after stopping motors
  }
  else {
    // Optional: stop motors when joystick not pushed
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
  }

  delay(50); // small delay to prevent spamming
}

