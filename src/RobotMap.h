#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

//Setings
//#define IMU
#define GAMEPAD

static const uint32_t DRIVER_JOY = 0; // The channels for the driver joystick
static const uint32_t GUNNER_JOY = 1; // The channels for the gunner joystick
#ifdef GAMEPAD
static const uint32_t LEFT_X  = 1; // port for left joystick, x axis
static const uint32_t LEFT_Y  = 0; // port for left joystick, y axis
static const uint32_t RIGHT_X = 4; // port for right joystick, x axis

#else

static const uint32_t LEFT_X  = 0; // port for left joystick, x axis
static const uint32_t LEFT_Y  = 1; // port for left joystick, y axis
static const uint32_t RIGHT_X = 2; // port for right joystick, x axis

static const uint32_t SLIDER = 3;
#endif

//TESTING
static const uint32_t BUTTON_A = 1; // port for A button on xbox controller
static const uint32_t BUTTON_B = 2; // port for B button on xbox controller
static const uint32_t BUTTON_X = 3; // port for X button on xbox controller
static const uint32_t BUTTON_Y = 4; // port for Y button on xbox controller
static const uint32_t BUTTON_RB = 6; // port for Y button on xbox controller
static const uint32_t BUTTON_L2 = 5;
static const uint32_t BUTTON_R2 = 6;

#endif
