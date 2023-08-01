
#ifndef CAMERA_H
#define CAMERA_H

#include "pch.h"
#include "Scene/Component.h"
#include "Maths/Matrix4.h"

namespace Aminophenol {

    class AMINOPHENOL_API Camera final
        : public Component
    {
    public:
		
        Camera(Node* node);
        ~Camera();

        void setOrthographicProjection(float left, float right, float bottom, float top, float near, float far);
        void setPerspectiveProjection(float fov, float aspect, float near, float far);
		
        Maths::Matrix4f getProjectionMatrix() const;

    private:
		
        Maths::Matrix4f m_projectionMatrix{ 1.0f };
		
    };

} // namespace Aminophenol

#endif // CAMERA_H
