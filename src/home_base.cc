/**
 * @file home_base.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/home_base.h"
#include "src/robot_motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
HomeBase::HomeBase(const struct home_base_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta, params->pos,
    params->color),
  heading_angle_(0),
  motion_handler_(),
  motion_behavior_(),
  sensor_touch_() {
    motion_handler_.heading_angle(200);
    motion_handler_.speed(5);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void HomeBase::TimestepUpdate(uint dt) {
  Position old_pos = get_pos();
  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(sensor_touch_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);


  srand((unsigned)time(0));
  int x = rand() % 10 + 1;
  if (x > 7) {
    motion_handler_.heading_angle(rand() % 360 +1);
  }
} /* TimestepUpdate() */

// Pass along a collision event (from arena) to the touch sensor.
// This method provides a framework in which sensors can get different
// types of information from different sources.
void HomeBase::Accept(EventCollision * e) {
  sensor_touch_.Accept(e);
}

void HomeBase::Accept(EventCommand * e) {
}

void HomeBase::Accept(EventRecharge * e) {
}

// User input commands to change heading or speed
void HomeBase::EventCmd(enum event_commands cmd) {
  motion_handler_.AcceptCommand(cmd);
} /* event_cmd() */

void HomeBase::Reset(void) {
  set_pos(Position(400, 400));
  motion_handler_.Reset();
  sensor_touch_.Reset();
} /* Reset() */


NAMESPACE_END(csci3081);
