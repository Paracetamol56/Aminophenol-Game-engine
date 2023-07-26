
#include "pch.h"
#include "Quaternion.h"

namespace Aminophenol::Maths
{

	const Quaternionf Quaternion<float>::zero(0.0f, 0.0f, 0.0f, 0.0f);
	const Quaternionf Quaternion<float>::identity(0.0f, 0.0f, 0.0f, 1.0f);

	const Quaterniond Quaternion<double>::zero(0.0, 0.0, 0.0, 0.0);
	const Quaterniond Quaternion<double>::identity(0.0, 0.0, 0.0, 1.0);

	const Quaternioni Quaternion<int>::zero(0, 0, 0, 0);
	const Quaternioni Quaternion<int>::identity(0, 0, 0, 1);

}
