
#ifndef CAMERA_H
#define CAMERA_H

#include "Scene/Component.h"
#include "Maths/Matrix4.h"

namespace Aminophenol {

    class Camera
        : public Component
    {
    public:
		
        Camera(Node* node);
        ~Camera() = default;

        virtual void setAspectRatio(float aspect) = 0;
        void setViewDirection(Maths::Vector3f direction, Maths::Vector3f up);
        void setViewTarget(Maths::Vector3f target, Maths::Vector3f up);

        Maths::Matrix4f getProjectionMatrix() const;
        Maths::Matrix4f getViewMatrix();

    protected:

        virtual void setProjection() = 0;
		
        Maths::Matrix4f m_projectionMatrix{ 1.0f };
        Maths::Matrix4f m_viewMatrix{ 1.0f };
		
    };

    class OrthographicCamera
        : public Camera
    {
    public:

        OrthographicCamera(Node* node, float aspect, float bottom, float top, float near, float far);
        ~OrthographicCamera() = default;

        void setAspectRatio(float aspect) override;

    private:

        void setProjection() override;

        float m_left;
        float m_right;
        float m_bottom;
        float m_top;
        float m_near;
        float m_far;
    };

    class PerspectiveCamera
        : public Camera
    {
    public:

        PerspectiveCamera(Node* node, float fov, float aspect, float near, float far);
        ~PerspectiveCamera() = default;

        void setAspectRatio(float aspect) override;

    private:

        void setProjection() override;

		float m_fov;
        float m_aspect;
		float m_near;
		float m_far;

	};

} // namespace Aminophenol

#endif // CAMERA_H
