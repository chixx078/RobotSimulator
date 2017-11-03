/**
 * @file home_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_HOME_BASE_H_
#define SRC_HOME_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/home_base_params.h"
#include "src/arena_mobile_entity.h"

#include "src/robot_motion_handler.h"
#include "src/robot_motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/event_collision.h"
#include "src/event_command.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief A child class of ArenaMobileEntity, representing a home base
  * home base changes heading angle randomly at random time.
  */
class HomeBase: public ArenaMobileEntity {
 public:
  explicit HomeBase(const struct home_base_params* const params);

  double heading_angle(void) const { return motion_handler_.heading_angle(); }
  void heading_angle(double ha) { motion_handler_.heading_angle(ha); }
  double speed(void) { return motion_handler_.speed(); }
  void speed(double sp) { motion_handler_.speed(sp); }

  void TimestepUpdate(unsigned int dt);

  void Accept(EventCommand * e);
  void Accept(EventCollision * e);
  void Accept(EventRecharge * e);

  void EventCmd(enum event_commands cmd);

  // reset home base to start location/heading angle
  void Reset(void);
  std::string name(void) const { return "Home Base"; }

 private:
  double heading_angle_;
  double angle_delta_;
  RobotMotionHandler motion_handler_;
  RobotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_HOME_BASE_H_
