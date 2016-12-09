
// define the parameters of our machine.
#define X_STEPS_PER_INCH 4800
#define X_STEPS_PER_MM   188.97
#define X_MOTOR_STEPS    200

#define Y_STEPS_PER_INCH 4800
#define Y_STEPS_PER_MM   188.97
#define Y_MOTOR_STEPS    200

#define Z_STEPS_PER_INCH 4800
#define Z_STEPS_PER_MM   188.97
#define Z_MOTOR_STEPS    200

//our maximum feedrates
#define FAST_XY_FEEDRATE 100
#define FAST_Z_FEEDRATE  100

// Units in curve section
#define CURVE_SECTION_INCHES 0.019685
#define CURVE_SECTION_MM 0.5

// Set to one if sensor outputs inverting (ie: 1 means open, 0 means closed)
// RepRap opto endstops are *not* inverting.
#define SENSORS_INVERTING 0

// How many temperature samples to take.  each sample takes about 100 usecs.


/****************************************************************************************
* digital i/o pin assignment
*
* this uses the undocumented feature of Arduino - pins 14-19 correspond to analog 0-5
****************************************************************************************/

//cartesian bot pins
#define X_STEP_PIN 8
#define X_DIR_PIN 9
#define X_MIN_PIN 4
#define X_MAX_PIN 2
#define X_ENABLE_PIN 15

#define Y_STEP_PIN 10
#define Y_DIR_PIN 11
#define Y_MIN_PIN 3
#define Y_MAX_PIN 5
#define Y_ENABLE_PIN 15

#define Z_STEP_PIN 12
#define Z_DIR_PIN 13
#define Z_MIN_PIN 7
#define Z_MAX_PIN 6
#define Z_ENABLE_PIN 15


