

void Lateral(directionType direction, double amount, rotationUnits unit, double speed, velocityUnits vUnit) {
  rightMotor.startRotateFor(direction, amount, unit, speed, vUnit);
  leftMotor.rotateFor(direction, amount, unit, speed, vUnit);
}

void Rotate(directionType direction, double amount, rotationUnits unit, double speed, velocityUnits vUnit) {
  rightMotor.startRotateFor(direction == forward ? reverse : forward, amount, unit, speed, vUnit);
  leftMotor.rotateFor(direction, amount, unit, speed, vUnit);
}

void Intake(directionType direction, double ammount, rotationUnits unit, double speed, velocityUnits vUnit) {
  rightIntakeMotor.startRotateFor(direction, ammount, unit, speed, vUnit);
  leftIntakeMotor.rotateFor(direction, ammount, unit, speed, vUnit);
}

void RampActuate(directionType direction, double ammount, rotationUnits unit) {
  actuatorMotor.startRotateFor(direction, ammount, unit);
}

void Lift(directionType direction, double ammount, rotationUnits unit, double speed, velocityUnits vUnit) {
  liftMotor.startRotateFor(direction, ammount, unit, speed, vUnit);
}

void setLiftBrake(vex::brakeType braketype) {
  liftMotor.setBrake(braketype);
}
