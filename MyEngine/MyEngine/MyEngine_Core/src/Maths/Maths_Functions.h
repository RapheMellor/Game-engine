#pragma once

//Defines the use of math statement eg: M_PI
#define _USE_MATH_DEFINES
//Include file
#include <math.h>

namespace MyEngine { namespace Maths {
	//Changes degrees to radians
		inline float toRadians(float degrees)
		{
			return degrees * (M_PI / 180.0f);
		}
} }