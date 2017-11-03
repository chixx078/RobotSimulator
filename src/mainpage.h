/**
 * @file graphics_arena_viewer.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage CSCI3081 Robot Simulator Project
 *
 * \section intro_sec Introduction
 *
 * This robot simulator allows you to play a game. The goal of the game is to make robot collide on home base before the robot battery runs out.

The graphicApp draw an arena in the viewer, with round entities and events happening on time in the arena. Entities include a robot with battery, 5 obstacles, home base and recharge station. Events can be collision event, recharge event and key press event.

For every timestep the simulation updates, the position of the entities are checked. If the position plus radius is out of bound, it means the entity collides on the wall, or if the the positions of two entities are smaller than the sum of radius, it means two entities collide. Then a collision event is created.

The robot and home base are mobile entities. When a mobile entity collides on other entity or on the wall, the sensor touch on the entity will accept a collision event, and the heading angle and velocity of the entity changes based on the angle of contact.

The battery level is displayed on the robot, collision and movement will deplete the battery, and colliding on recharge station will trigger a recharge event and set the battery to maximum.
When the robot collides on obstacles or walls, the speed reduces by half and battery reduced by 10.
Home base changes heading angle randomly at random time.

You can press key left/right key to control the heading angle of robot, and up/down key to control the speed. When a key is pressed, robot motion handler will accept a event command to according to the key and change the heading angle and velocity.

When robot collides on home base, you win. When the battery runs out, you lose. So pay attention to the battery level and go to recharge station as needed.

You can pause/play or restart the game during anytime of the game.
 *
 * \section install_sec Installation
 *
 * \subsection libsimplegraphics Installing and Using libsimplegraphics
 *
 * etc...
 */

#endif  // SRC_MAINPAGE_H_
