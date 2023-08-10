
#include "ObjectRotationController.h"

#include "Core/Engine.h"
#include "Scene/Node.h"
#include "Maths/Vector3.h"
#include "Maths/Quaternion.h"

ObjectRotationController::ObjectRotationController(Node* node)
	: Component(node)
{}

void ObjectRotationController::onStart()
{
	m_xAxis = Engine::get()->getInputSystem().addAxis("ObjectRotationX", KeyCode::Left, KeyCode::Right, 0.01f, 0.01f);
	m_yAxis = Engine::get()->getInputSystem().addAxis("ObjectRotationY", KeyCode::Down, KeyCode::Up, 0.01f, 0.01f);
	m_autoRotateButton = Engine::get()->getInputSystem().addButton("ObjectAutoRotate", KeyCode::Space);
}

void ObjectRotationController::onUpdate()
{
	const float deltaX = m_xAxis->getValue() / 1000.0f;
	const float deltaY = m_yAxis->getValue() / 1000.0f;

	if (deltaX != 0.0f || deltaY != 0.0f)
		m_node->transform.rotation *= Maths::Quaternion(Maths::Vector3f{ 0.0f, deltaX, deltaY });

	if (m_autoRotateButton->isPressed())
		m_autoRotate = !m_autoRotate;

	if (m_autoRotate)
		m_node->transform.rotation *= Maths::Quaternion(Maths::Vector3f{ 0.0f, 0.0002f, -0.0001f });
}
