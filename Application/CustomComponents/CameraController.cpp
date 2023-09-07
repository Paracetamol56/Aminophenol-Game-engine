
#include "CameraController.h"
#include "Core/Engine.h"
#include "Maths/Vector3.h"
#include <ostream>

CameraController::CameraController(Node* node)
	: Component{ node }
	, m_inputSystem{ Engine::get()->getInputSystem() }
{}

void CameraController::onStart()
{
	m_moveForwardAxis = m_inputSystem.addAxis("CameraMoveForward", KeyCode::W, KeyCode::S, 0.1f, 0.1f);
	m_moveRightAxis = m_inputSystem.addAxis("CameraMoveRight", KeyCode::A, KeyCode::D, 0.1f, 0.1f);
	m_moveUpAxis = m_inputSystem.addAxis("CameraMoveUp", KeyCode::E, KeyCode::Q, 0.1f, 0.1f);
	
	m_focusButton = m_inputSystem.addButton("CameraFocus", MouseButton::Left);
	m_rotateXAxis = m_inputSystem.addAxis("CameraRotateX", KeyCode::Left, KeyCode::Right, 0.1f, 0.1f);
	m_rotateYAxis = m_inputSystem.addAxis("CameraRotateY", KeyCode::Down, KeyCode::Up, 0.1f, 0.1f);
	m_lastMousePosition = Engine::get()->getWindow().getSizeVector() / 2; // m_inputSystem.getMousePosition();
}

void CameraController::onUpdate()
{
	// If the mose is clicked, toggle mouse focus
	if (m_focusButton->wasPressed())
	{
		m_mouseFocus = !m_mouseFocus;
		m_inputSystem.setCursorMode(m_mouseFocus ? CursorMode::Hidden : CursorMode::Normal);
	}

	const float deltaTime = Engine::get()->getDeltaTime();

	const float moveForward = m_moveForwardAxis->getValue() * deltaTime * m_moveSpeed;
	const float moveRight = m_moveRightAxis->getValue() * deltaTime * m_moveSpeed;
	const float moveUp = m_moveUpAxis->getValue() * deltaTime * m_moveSpeed;
	// Maths::Vector2<double> rotateDelta = (m_inputSystem.getMousePosition() - m_lastMousePosition) * deltaTime;

	if (std::abs(moveForward) > std::numeric_limits<float>::epsilon())
	{
		m_node->transform.position -= m_node->transform.getForward() * moveForward;
	}

	if (std::abs(moveRight) > std::numeric_limits<float>::epsilon())
	{
		m_node->transform.position -= m_node->transform.getRight() * moveRight;
	}

	if (std::abs(moveUp) > std::numeric_limits<float>::epsilon())
	{
		m_node->transform.position += m_node->transform.getUp() * moveUp;
	}

	/*if (m_mouseFocus && rotateDelta.magnitude() > std::numeric_limits<double>::epsilon())
	{
		Maths::Vector3f eulerRotation = m_node->transform.rotation.toEulerAngles(Maths::EulerAngle::YXZ);
		// Maths::Vector3f test = eulerRotation;
		Maths::Vector3f test = m_node->transform.getUp();
		std::cout << "Euler rotation: " << test.x << ", " << test.y << ", " << test.z << std::endl;
		
		m_node->transform.rotation = Maths::Quaternionf {
			Maths::Vector3f {
				eulerRotation.x + static_cast<float>(rotateDelta.x) / 10.0f,
				eulerRotation.y + static_cast<float>(rotateDelta.y) / 10.0f,
				0.0f
			},
			Maths::EulerAngle::YXZ
		};
		m_inputSystem.setMousePosition(Engine::get()->getWindow().getSizeVector() / 2);
	}*/

	float rotateX = m_rotateXAxis->getValue() * deltaTime * m_rotateSpeed;
	float rotateY = m_rotateYAxis->getValue() * deltaTime * m_rotateSpeed;

	if (
		std::abs(rotateX) > std::numeric_limits<float>::epsilon() ||
		std::abs(rotateY) > std::numeric_limits<float>::epsilon()
	)
	{
		Maths::Vector3f eulerRotation = m_node->transform.rotation.toEulerAngles(Maths::EulerAngle::YXZ);

		m_node->transform.rotation = Maths::Quaternionf{
			Maths::Vector3f {
				eulerRotation.x + static_cast<float>(rotateX),
				eulerRotation.y + static_cast<float>(rotateY),
				0.0f
			},
			Maths::EulerAngle::YXZ
		};
		m_node->transform.rotation.normalize();

		// the forward and up vectors must be orthogonal, log the dot product to check
		std::cout << "Dot product: " << m_node->transform.getForward().dot(m_node->transform.getUp()) << std::endl;
	}
}
