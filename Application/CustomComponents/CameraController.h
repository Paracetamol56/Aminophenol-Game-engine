
#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include "Scene/Component.h"
#include "Input/InputSystem.h"
#include "Input/InputAxis.h"
#include "Input/InputMouseButton.h"
#include "Maths/Vector2.h"
#include "Maths/Vector3.h"

using namespace Aminophenol;

class CameraController :
    public Component
{
public:

    CameraController(Node* node);
    ~CameraController() = default;

    void onStart() override;
    void onUpdate() override;

private:

    InputSystem& m_inputSystem;

    bool m_mouseFocus = false;
    std::shared_ptr<InputAxis> m_moveForwardAxis{ nullptr };
    std::shared_ptr<InputAxis> m_moveRightAxis{ nullptr };
    std::shared_ptr<InputAxis> m_moveUpAxis{ nullptr };

    std::shared_ptr<InputButton> m_focusButton{ nullptr };
    std::shared_ptr<InputAxis> m_rotateXAxis{ nullptr };
    std::shared_ptr<InputAxis> m_rotateYAxis{ nullptr };
    Maths::Vector2<double> m_lastMousePosition{ 0.0, 0.0 };
    float m_moveSpeed = 1.0f;
    float m_rotateSpeed = 0.25f;

};

#endif // !CAMERA_CONTROLLER_H
