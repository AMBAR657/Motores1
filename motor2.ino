#include <Stepper.h>
int stepperRevolution = 2048;
int motSpeed =12;
Stepper myStepper (stepperRevolution,8,10,9,11);
int dt = 1500;

void setup() {
  // put your setup code here, to run once:
myStepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
myStepper.step(stepperRevolution);
delay(dt);
myStepper.step(-stepperRevolution);
delay(dt);
}