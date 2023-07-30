
#ifndef TRANSFORM3_H
#define TRANSFORM3_H

#include "pch.h"
#include "Vector3.h"
#include "Quaternion.h"

namespace Aminophenol::Maths
{

	class Transform3
	{
	public:

		Transform3();

	private:

		Vector3f m_position;
		Quaternionf m_rotation;
		Vector3f m_scale;

	};

}
#endif // TRANSFORM3_H
