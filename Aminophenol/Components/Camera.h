
#ifndef CAMERA_H
#define CAMERA_H

#include "Scene/Component.h"
#include "Maths/Matrix4.h"

namespace Aminophenol {

    class Camera final
        : public Component
    {
    public:
		
        Camera(Node* node);
        ~Camera();

        void setOrthographicProjection(float left, float right, float bottom, float top, float near, float far);
        void setPerspectiveProjection(float fov, float aspect, float near, float far);
		
        void setViewDirection(Maths::Vector3f direction, Maths::Vector3f up);
        void setViewTarget(Maths::Vector3f target, Maths::Vector3f up);

        Maths::Matrix4f getProjectionMatrix() const;
        Maths::Matrix4f getViewMatrix() const;

    private:
		
        Maths::Matrix4f m_projectionMatrix{ 1.0f };
        Maths::Matrix4f m_viewMatrix{ 1.0f };
		
    };

} // namespace Aminophenol

#endif // CAMERA_H
