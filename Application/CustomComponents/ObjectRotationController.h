
#ifndef OBJECT_ROTATION_CONTROLLER_H
#define OBJECT_ROTATION_CONTROLLER_H

#include "Scene\Component.h"
#include "Input\InputAxis.h"
#include "Input\InputButton.h"

using namespace Aminophenol;

class ObjectRotationController :
    public Component
{

public:
	ObjectRotationController(Node* node, const float speed);
	~ObjectRotationController() = default;

	void onStart() override;
	void onUpdate() override;

private:

	const float _speed;
	std::shared_ptr<InputAxis> m_xAxis;
	std::shared_ptr<InputAxis> m_yAxis;
	std::shared_ptr<InputButton> m_autoRotateButton;
	bool m_autoRotate = true;

};

#endif // !OBJECT_ROTATION_CONTROLLER_H
