
#ifndef TRANSFORM3_H
#define TRANSFORM3_H

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
		Matrix4f getNormalMatrix() const;
		Vector3f getForward() const;
		Vector3f getBack() const;
		Vector3f getRight() const;
		Vector3f getLeft() const;
		Vector3f getUp() const;
		Vector3f getDown() const;

		void move(const Vector3f& offset);
		void move(float x, float y, float z);
		void rotate(const Quaternionf& rotation);

		Vector3f position;
		Quaternionf rotation;
		Vector3f scale;

	};

}
#endif // TRANSFORM3_H
