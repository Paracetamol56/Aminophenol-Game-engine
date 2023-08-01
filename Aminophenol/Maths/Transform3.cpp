
#include "pch.h"
#include "Transform3.h"

namespace Aminophenol::Maths
{

	Transform3::Transform3()
		: m_position(0.0f, 0.0f, 0.0f)
		, m_rotation(0.0f, 0.0f, 0.0f, 1.0f)
		, m_scale(1.0f, 1.0f, 1.0f)
	{}

	Transform3::Transform3(const Vector3f& position, const Quaternionf& rotation, const Vector3f& scale)
		: m_position(position)
		, m_rotation(rotation)
		, m_scale(scale)
	{}

	Transform3::Transform3(const Transform3& other)
		: m_position(other.m_position)
		, m_rotation(other.m_rotation)
		, m_scale(other.m_scale)
	{}

	Transform3::Transform3(Transform3&& other)
		: m_position(std::move(other.m_position))
		, m_rotation(std::move(other.m_rotation))
		, m_scale(std::move(other.m_scale))
	{}

	Matrix4f Transform3::getMatrix() const
	{
		Matrix4f result = Matrix4f::identity;

		result *= Matrix4f::translation(m_position);
		result *= Matrix4f::rotation(m_rotation);
		result *= Matrix4f::scale(m_scale);

		return result;
	}

}
