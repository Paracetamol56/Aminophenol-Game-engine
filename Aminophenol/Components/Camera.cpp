
#include "pch.h"
#include "Camera.h"
#include "Scene/Node.h"

namespace Aminophenol {

	Camera::Camera(Node* node)
		: Component(node)
	{}

	void Camera::setViewDirection(Maths::Vector3f direction, Maths::Vector3f up)
	{
		// Check that the direction and up vectors are not collinear and not zero
		if (direction == Maths::Vector3f::zero())
			throw std::runtime_error("Camera::setViewDirection() - direction cannot be zero.");
		if (up == Maths::Vector3f::zero())
			throw std::runtime_error("Camera::setViewDirection() - up cannot be zero.");
		if (direction == up || direction == -up)
			throw std::runtime_error("Camera::setViewDirection() - direction and up cannot be collinear.");

		Maths::Vector3f position = m_node->transform.position;

		// Orthonormal basis
		const Maths::Vector3f w = direction.normalize();
		const Maths::Vector3f u = up.cross(w).normalize();
		const Maths::Vector3f v = w.cross(u);

		m_viewMatrix = Maths::Matrix4f::identity();

		m_viewMatrix[0][0] = u.x;
		m_viewMatrix[0][1] = u.y;
		m_viewMatrix[0][2] = u.z;
		m_viewMatrix[0][3] = -u.dot(position);
		m_viewMatrix[1][0] = v.x;
		m_viewMatrix[1][1] = v.y;
		m_viewMatrix[1][2] = v.z;
		m_viewMatrix[1][3] = -v.dot(position);
		m_viewMatrix[2][0] = w.x;
		m_viewMatrix[2][1] = w.y;
		m_viewMatrix[2][2] = w.z;
		m_viewMatrix[2][3] = -w.dot(position);
	}

	void Camera::setViewTarget(Maths::Vector3f target, Maths::Vector3f up)
	{
		Maths::Vector3f direction = target - m_node->transform.position;
		setViewDirection(direction, up);
	}

	OrthographicCamera::OrthographicCamera(Node* node, float aspect, float bottom, float top, float near, float far)
		: Camera(node)
		, m_left(-aspect)
		, m_right(aspect)
		, m_bottom(bottom)
		, m_top(top)
		, m_near(near)
		, m_far(far)
	{
		if (aspect <= 0.0f)
			throw std::runtime_error("OrthographicCamera::OrthographicCamera() - aspect cannot be less than or equal to zero.");
		setProjection();
	}

	void OrthographicCamera::setAspectRatio(float aspect)
	{
		if (aspect <= 0.0f)
			throw std::runtime_error("OrthographicCamera::setAspectRation() - aspect cannot be less than or equal to zero.");
		
		m_left = -aspect;
		m_right = aspect;
		setProjection();
	}

	void OrthographicCamera::setProjection()
	{
		m_projectionMatrix = Maths::Matrix4f::identity();

		m_projectionMatrix[0][0] = 2.0f / (m_right - m_left);
		m_projectionMatrix[1][1] = 2.0f / (m_top - m_bottom);
		m_projectionMatrix[2][2] = 1.0f / (m_far - m_near);
		m_projectionMatrix[3][0] = - (m_right + m_left) / (m_right - m_left);
		m_projectionMatrix[3][1] = - (m_top + m_bottom) / (m_top - m_bottom);
		m_projectionMatrix[3][2] = - m_near / (m_far - m_near);
	}

	PerspectiveCamera::PerspectiveCamera(Node* node, float fov, float aspect, float near, float far)
		: Camera(node)
		, m_fov(fov)
		, m_aspect(aspect)
		, m_near(near)
		, m_far(far)
	{
		if (fov <= 0.0f)
			throw std::runtime_error("PerspectiveCamera::PerspectiveCamera() - fov cannot be less than or equal to zero.");
		if (aspect <= 0.0f)
			throw std::runtime_error("PerspectiveCamera::PerspectiveCamera() - aspect cannot be less than or equal to zero.");
		
		setProjection();
	}

	void PerspectiveCamera::setAspectRatio(float aspect)
	{
		if (aspect <= 0.0f)
			throw std::runtime_error("PerspectiveCamera::setAspectRation() - aspect cannot be less than or equal to zero.");
		
		m_aspect = aspect;
		setProjection();
	}

	void PerspectiveCamera::setProjection()
	{
		const float tanHalfFovy = tanf(m_fov / 2.0f);

		m_projectionMatrix = Maths::Matrix4f::identity();

		m_projectionMatrix[0][0] = 1.0f / (m_aspect * tanHalfFovy);
		m_projectionMatrix[1][1] = 1.0f / (tanHalfFovy);
		m_projectionMatrix[2][2] = m_far / (m_far - m_near);
		m_projectionMatrix[2][3] = - (m_far * m_near) / (m_far - m_near);
		m_projectionMatrix[3][2] = 1.0f;
		m_projectionMatrix[3][3] = 0.0f;
	}

	Maths::Matrix4f Camera::getProjectionMatrix() const
	{
		return m_projectionMatrix;
	}

	Maths::Matrix4f Camera::getViewMatrix()
	{
		setViewDirection(m_node->transform.getForward(), m_node->transform.getUp());
		return m_viewMatrix;
	}

} // namespace Aminophenol