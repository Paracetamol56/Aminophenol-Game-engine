
#ifndef TRANSFORM3_H
#define TRANSFORM3_H

#include "pch.h"
#include "Vector3.h"
#include "Matrix4.h"
#include "Quaternion.h"

namespace Aminophenol::Maths
{

	class Transform3
	{
	public:

		Transform3();

		Transform3(const Vector3f& position, const Quaternionf& rotation, const Vector3f& scale);

		Transform3(const Transform3& other);

		Transform3(Transform3&& other);

		Matrix4f getMatrix() const;

		Vector3f position;
		Quaternionf rotation;
		Vector3f scale;

	};

}
#endif // TRANSFORM3_H
