
#include "ObjectRotationController.h"

#include "Core/Engine.h"
#include "Scene/Node.h"
#include "Maths/Vector3.h"
#include "Maths/Quaternion.h"

ObjectRotationController::ObjectRotationController(Node* node, const float speed)
	: Component(node)
	, _speed(speed)
{}

void ObjectRotationController::onStart()
{
	m_xAxis = Engine::get()->getInputSystem().addAxis("ObjectRotationX", KeyCode::Left, KeyCode::Right, 0.1f, 0.1f);
	m_yAxis = Engine::get()->getInputSystem().addAxis("ObjectRotationY", KeyCode::Down, KeyCode::Up, 0.1f, 0.1f);
	m_autoRotateButton = Engine::get()->getInputSystem().addButton("ObjectAutoRotate", KeyCode::Space);
}

void ObjectRotationController::onUpdate()
{
	const float deltaX = m_xAxis->getValue() * Engine::get()->getDeltaTime() * _speed;
	const float deltaY = m_yAxis->getValue() * Engine::get()->getDeltaTime() * _speed;

	if (std::abs(deltaX) > std::numeric_limits<float>::epsilon() || std::abs(deltaY) > std::numeric_limits<float>::epsilon())
	{
		Maths::Vector3f eulerRotation = m_node->transform.rotation.toEulerAngles(Maths::EulerAngle::YXZ);
		m_node->transform.rotation = Maths::Quaternion(Maths::Vector3f{ 0.0f, eulerRotation.y + deltaX, (eulerRotation.z + deltaY) }, Maths::EulerAngle::YXZ);
	}

	if (m_autoRotateButton->wasPressed())
		m_autoRotate = !m_autoRotate;

	if (m_autoRotate)
		m_node->transform.rotation *= Maths::Quaternion(Maths::Vector3f{ 0.0f, 0.5f * Engine::get()->getDeltaTime() * _speed, 0.0f });
}
