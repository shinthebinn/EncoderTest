/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ExampleSubsystem.h"

ExampleSubsystem::ExampleSubsystem() {
  // Implementation of subsystem constructor goes here.
  const double circumference = 6 * M_PI;

  Encoder1.SetDistancePerPulse(circumference / 360);
  Encoder2.SetDistancePerPulse(circumference / 360);
}

void ExampleSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.

  bool direction1 = !(Encoder1.GetDirection());
  bool direction2 = Encoder2.GetDirection();
  bool moving1 = (Encoder1.GetRate() != 0.0);
  bool moving2 = (Encoder2.GetRate() != 0.0);

  if (!moving1 and !moving2) {
    printf("not moving\n");
  } else if (moving1 and direction1) {
    if (moving2 and direction2) {
      printf("moving forward\n");
    } else if (!moving2 or !direction2)  {
      printf("turning left\n");
    }
  } else {
    if (moving2 and direction2) {
      printf("turning right\n");
    } else if (moving2 and moving1 and !direction1 and !direction2) {
      printf("moving backwards\n");
    }
  }
}
//sus