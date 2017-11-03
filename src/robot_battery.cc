/**
 * @file robot_battery.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include "src/robot_battery.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double RobotBattery::Deplete(__unused Position old_pos,
  __unused Position new_pos, __unused double dt) {
  /* @todo deplete battery by some value based on movement and speed */
  double old_x = old_pos.x;
  double old_y = old_pos.y;
  double new_x = new_pos.x;
  double new_y = new_pos.y;

  if ( (old_x == new_x) && (old_y == new_y) ) {
    return charge_;
  }

  double dist = std::sqrt(std::pow(new_x - old_x, 2) +
  std::pow(new_y - old_y, 2));
  double speed = dist/dt;
  double speed_dep = speed * kLINEAR_SCALE_FACTOR;

  if ((charge_ - (kBASE_DEPLETION + speed_dep)) >= 0) {
    charge_ -= (kBASE_DEPLETION + speed_dep);
  } else {
    charge_ = 0;
  }

  return charge_;
} /* deplete() */

void Accept(__unused EventCollision * e) {
  /* @todo deplete battery by some value -- arbitrary selected for bumping */
}

NAMESPACE_END(csci3081);
