#pragma once

/*
 Author - Odyssey.
 Specially developed maths library of game development.
 Heavily commented for the user to be able to understand easily.
 */

#include <cmath>

/** stores the vaule of 1/PI constant */
#define INV_PI (0.31830988618f)
/** stores the vaule of 1/2 * PI constant */
#define HLF_PI (1.57079632679f)

#undef PI
/** stores the vaule of PI constant */
#define PI (3.14159265359f)
/** stores the vaule of 2 * PI constant */
#define PI2 (6.28318530718f)

/** fraction for converting Degrees to Radians */
#define DEG_TO_RAD (PI / 180.0f)
/** fraction for converting Radians to Degrees */
#define RAD_TO_DEG (180.0f / PI)

namespace odm
{
	static float DegToRad(float angle) { return (angle * DEG_TO_RAD); }
	static float RadToDeg(float angle) { return (angle * RAD_TO_DEG); }
}