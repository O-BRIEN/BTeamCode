/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// rightMotor           motor         3               
// leftMotor            motor         17              
// liftMotor            motor         4               
// rightIntakeMotor     motor         5               
// leftIntakeMotor      motor         8               
// actuatorMotor        motor         16              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  liftMotor.setBrake(brakeType::hold);

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

  Lateral(forward, 2, turns, 100, velocityUnits::pct);

  vex::task::sleep(1000);

  Lateral(reverse, 2, turns, 100, velocityUnits::pct);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  // Where my dad go?
  while (1) {
    leftMotor.spin(forward, Controller1.Axis3.position() + Controller1.Axis1.position(),
                   percentUnits::pct);
    rightMotor.spin(forward, Controller1.Axis3.position() - Controller1.Axis1.position(),                  
                   percentUnits::pct);


    if (Controller1.ButtonX.pressing()) {

      liftMotor.spin(fwd, 100, pct);

    } else if (Controller1.ButtonB.pressing()) {
      liftMotor.spin(reverse, 100, pct);

    } else {
      liftMotor.stop();
    }


    if (Controller1.ButtonL1.pressing()) {
      rightIntakeMotor.spin(forward, 100, pct);
      leftIntakeMotor.spin(forward, 100, pct);
    }else if (Controller1.ButtonR1.pressing()) {
      leftIntakeMotor.spin(reverse, 100, pct);
      rightIntakeMotor.spin(reverse, 100, pct);
    } else {
      leftIntakeMotor.stop();
      rightIntakeMotor.stop();
    }

    if(Controller1.ButtonL2.pressing()) {
      actuatorMotor.spin(forward, 100, velocityUnits::pct);
    } else if (Controller1.ButtonR2.pressing()) {
      actuatorMotor.spin(reverse, 100, percentUnits::pct);
    }
    else {
      actuatorMotor.stop();
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
