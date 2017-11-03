/**
 * @file robot_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
RobotMotionHandler::RobotMotionHandler() :
  heading_angle_(0),
  speed_(0),
  max_speed_(50) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void RobotMotionHandler::AcceptCommand(enum event_commands cmd) {
  double delta = 10;

  switch (cmd) {
  case COM_TURN_LEFT:
  if (heading_angle_ >=360) {
    heading_angle_ -= 360;
  }
  heading_angle_ -= delta;
  break;

  case COM_TURN_RIGHT:
  if (heading_angle_ >=360) {
    heading_angle_ -= 360;
  }
  heading_angle_ += delta;
  break;

  case COM_SPEED_UP:
  if ((speed_+ 0.5) <= max_speed_) {
    speed_ += 0.5;
  }
  break;

  case COM_SLOW_DOWN:
  if ((speed_- 0.5) >= 0) {
    speed_ -= 0.5;
  }
  break;

  default:
    std::cerr << "FATAL: bad actuator command" << std::endl;
    assert(0);
  } /* switch() */
} /* accept_command() */

void RobotMotionHandler::UpdateVelocity(SensorTouch st) {
  if (st.activated()) {
    heading_angle_ = - st.angle_of_contact();
  }
}

NAMESPACE_END(csci3081);
