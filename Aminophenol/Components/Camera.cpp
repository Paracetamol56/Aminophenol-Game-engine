
#include "pch.h"
#include "Camera.h"

#include "Scene/Node.h"

namespace Aminophenol {

	Camera::Camera(Node* node)
		: Component(node)
	{}

	Camera::~Camera()
	{}

	void Camera::setOrthographicProjection(float left, float right, float bottom, float top, float near, float far)
	{
		m_projectionMatrix = Maths::Matrix4f::identity();

		m_projectionMatrix[0][0] = 2.0f / (right - left);
		m_projectionMatrix[1][1] = 2.0f / (top - bottom);
		m_projectionMatrix[2][2] = 1.0f / (far - near);
		m_projectionMatrix[3][0] = -(right + left) / (right - left);
		m_projectionMatrix[3][1] = -(top + bottom) / (top - bottom);
		m_projectionMatrix[3][2] = -near / (far - near);
	}

	void Camera::setPerspectiveProjection(float fov, float aspect, float near, float far)
	{
		assert(aspect != 0.0f);
		const float tanHalfFovy = tanf(fov / 2.0f);

		m_projectionMatrix = Maths::Matrix4f::identity();

		m_projectionMatrix[0][0] = 1.0f / (aspect * tanHalfFovy);
		m_projectionMatrix[1][1] = 1.0f / (tanHalfFovy);
		m_projectionMatrix[2][2] = far / (far - near);
		m_projectionMatrix[2][3] = - (far * near) / (far - near);
		m_projectionMatrix[3][2] = 1.0f;
		m_projectionMatrix[3][3] = 0.0f;
	}

	void Camera::setViewDirection(Maths::Vector3f direction, Maths::Vector3f up)
	{
		// Check that the direction and up vectors are not collinear and not zero
		assert(direction != Maths::Vector3f::zero());
		assert(up != Maths::Vector3f::zero());
		assert(direction != up && direction != -up);

		Maths::Vector3f position = m_node->transform.position;

		// Orthonormal basis
		const Maths::Vector3f w = direction.normalize();
		const Maths::Vector3f u = up.cross(w).normalize();
		const Maths::Vector3f v = w.cross(u);

		m_viewMatrix = Maths::Matrix4f::identity();

		m_viewMatrix[0][0] = u.x;
		m_viewMatrix[0][1] = u.y;
		m_viewMatrix[0][2] = u.z;
		m_viewMatrix[0][3] = - u.dot(position);
		m_viewMatrix[1][0] = v.x;
		m_viewMatrix[1][1] = v.y;
		m_viewMatrix[1][2] = v.z;
		m_viewMatrix[1][3] = - v.dot(position);
		m_viewMatrix[2][0] = w.x;
		m_viewMatrix[2][1] = w.y;
		m_viewMatrix[2][2] = w.z;
		m_viewMatrix[2][3] = - w.dot(position);
	}

	void Camera::setViewTarget(Maths::Vector3f target, Maths::Vector3f up)
	{
		Maths::Vector3f direction = target - m_node->transform.position;
		setViewDirection(direction, up);
	}

	Maths::Matrix4f Camera::getProjectionMatrix() const
	{
		return m_projectionMatrix;
	}

	Maths::Matrix4f Camera::getViewMatrix() const
	{
		return m_viewMatrix;
	}

} // namespace Aminophenol