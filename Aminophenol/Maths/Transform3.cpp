
#include "pch.h"
#include "Transform3.h"

namespace Aminophenol::Maths
{

	Transform3::Transform3()
		: position(0.0f, 0.0f, 0.0f)
		, rotation(0.0f, 0.0f, 0.0f, 1.0f)
		, scale(1.0f, 1.0f, 1.0f)
	{}

	Transform3::Transform3(const Vector3f& position, const Quaternionf& rotation, const Vector3f& scale)
		: position(position)
		, rotation(rotation)
		, scale(scale)
	{}

	Transform3::Transform3(const Transform3& other)
		: position(other.position)
		, rotation(other.rotation)
		, scale(other.scale)
	{}

	Transform3::Transform3(Transform3&& other)
		: position(std::move(other.position))
		, rotation(std::move(other.rotation))
		, scale(std::move(other.scale))
	{}

	Matrix4f Transform3::getMatrix() const
	{
		Matrix4f result = Matrix4f::identity();

		result *= Matrix4f::translation(position);
		result *= Matrix4f::rotation(rotation);
		result *= Matrix4f::scale(scale);

		return result;
	}

	Matrix4f Transform3::getNormalMatrix() const
	{
		Matrix4f result = Matrix4f::identity();

		result *= Matrix4f::rotation(rotation);
		result *= Matrix4f::scale(scale).inverse();

		return result;
	}

	Vector3f Transform3::getForward() const
	{
		return rotation.conjugate() * Vector3f::forward();
	}

	Vector3f Transform3::getBack() const
	{
		return rotation.conjugate() * Vector3f::backward();
	}

	Vector3f Transform3::getRight() const
	{
		return rotation.conjugate() * Vector3f::right();
	}

	Vector3f Transform3::getLeft() const
	{
		return rotation.conjugate() * Vector3f::left();
	}

	Vector3f Transform3::getUp() const
	{
		return rotation.conjugate() * Vector3f::up();
	}

	Vector3f Transform3::getDown() const
	{
		return rotation.conjugate() * Vector3f::down();
	}

	void Transform3::move(const Vector3f& offset)
	{
		position += rotation * offset;
	}

	void Transform3::move(float x, float y, float z)
	{
		move(Vector3f(x, y, z));
	}

	void Transform3::rotate(const Quaternionf& rotation)
	{
		this->rotation *= rotation;
	}

}
