
#include "pch.h"
#include "Camera.h"

namespace Aminophenol {

	Camera::Camera(Node* node)
		: Component(node)
	{}

	Camera::~Camera()
	{}

	void Camera::setOrthographicProjection(float left, float right, float bottom, float top, float near, float far)
	{
		m_projectionMatrix = Maths::Matrix4f::identity;

		m_projectionMatrix[0][0] = 2.0f / (right - left);
		m_projectionMatrix[1][1] = 2.0f / (top - bottom);
		m_projectionMatrix[2][2] = 1.0f / (far - near);
		m_projectionMatrix[3][0] = - (right + left) / (right - left);
		m_projectionMatrix[3][1] = - (bottom + top) / (bottom - top);
		m_projectionMatrix[3][2] = - near / (far - near);
	}

	void Aminophenol::Camera::setPerspectiveProjection(float fov, float aspect, float near, float far)
	{
		assert(aspect != 0.0f);
		const float tanHalfFovy = tanf(fov / 2.0f);

		m_projectionMatrix = Maths::Matrix4f::zero;

		m_projectionMatrix[0][0] = 1.0f / (aspect * tanHalfFovy);
		m_projectionMatrix[1][1] = 1.0f / tanHalfFovy;
		m_projectionMatrix[2][2] = far / (far - near);
		m_projectionMatrix[2][3] = 1.0f;
		m_projectionMatrix[3][2] = -(far * near) / (far - near);
	}

	Maths::Matrix4f Camera::getProjectionMatrix() const
	{
		return m_projectionMatrix;
	}

} // namespace Aminophenol