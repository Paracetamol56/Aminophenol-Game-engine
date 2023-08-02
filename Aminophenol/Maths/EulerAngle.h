
#ifndef EULER_ANGLE_H
#define EULER_ANGLE_H

#include "pch.h"

namespace Aminophenol::Maths
{

	// Wikipedia source: https://en.wikipedia.org/wiki/Euler_angles

	// Tait-Bryan euler angles
	enum class EulerAngle
	{
		XYZ,
		XZY,
		YXZ,
		YZX,
		ZXY,
		ZYX
	};

}

#endif // EULER_ANGLE_H
