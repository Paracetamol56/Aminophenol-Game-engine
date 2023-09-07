
#include <memory>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "Core/Engine.h"
#include "Logging/Logger.h"
#include "Mesh/OBJLoader.h"
#include "Mesh/PrimitiveMesh.h"
#include "Rendering/Image/Texture.h"

#include "CustomComponents/ObjectRotationController.h"
#include "CustomComponents/CameraController.h"

using namespace Aminophenol;

int main(int argc, char* argv[])
{
	// Initialize logger
#if _DEBUG
	Logger logger{ LogLevel::Trace };
#else
	Logger logger{ LogLevel::Info };
#endif // _DEBUG

	Engine engine{ "Aminophenol application", 60.0, 720, 720 };
	// engine.getWindow().setMaximized(true);

	try
	{
		// Create a basic scene
		std::shared_ptr<Scene> scene = std::make_shared<Scene>("Basic scene");
		engine.setActiveScene(scene);

		Node* object = scene->addChild("object");
		object->transform.position = { 0.0f, 0.0f, 0.0f };
		object->transform.rotation = Maths::Quaternionf({ 0.0f, 0.0f, 0.0f }, Maths::EulerAngle::YXZ);
		object->transform.scale = { 0.2f, 0.2f, 0.2f };
		MeshRenderer* objectMeshRenderer = object->addComponent<MeshRenderer>(OBJLoader::loadMesh(
			engine.getRenderingEngine().getLogicalDevice(),
			engine.getRenderingEngine().getCommandPool(),
			"C:/Users/mathe/Downloads/xyz-gizmo.obj"
		));
		object->addComponent<CameraController>();
		/*MeshRenderer* objectMeshRenderer = object->addComponent<MeshRenderer>(PrimitiveMesh::createCube(
			engine.getRenderingEngine().getLogicalDevice(),
			engine.getRenderingEngine().getCommandPool()
		));*/

		Node* floor = scene->addChild("floor");
		floor->transform.position = { 0.0f, -1.0f, 0.0f };
		floor->transform.scale = { 100.0f, 100.0f, 100.0f };
		MeshRenderer* floorMeshRenderer = floor->addComponent<MeshRenderer>(PrimitiveMesh::createPlane(
			engine.getRenderingEngine().getLogicalDevice(),
			engine.getRenderingEngine().getCommandPool()
		));

		Node* camera = scene->addChild("Camera");
		camera->transform.position = { 0.0f, 0.0f, -3.0f };
		camera->addComponent<CameraController>();
		// OrthographicCamera* cameraComponent = camera->addComponent<OrthographicCamera>(1.0, -1.0, 1.0, 0.0, 100.0);
		PerspectiveCamera* cameraComponent = camera->addComponent<PerspectiveCamera>(Maths::degreesToRadians(45.0f), 1.0f, 0.1f, 100.0f);
		cameraComponent->setViewDirection({ 0.0f, 0.0f, 1.0f }, { 0.0f, -1.0f, 0.0f });

		scene->setBackgroundColor(Maths::Color{0.0f, 0.0f, 0.0f, 1.0f});
		scene->setActiveCamera(cameraComponent);
		scene.reset();

		engine.run();
	}
	catch (const std::exception& e)
	{
		Logger::log(LogLevel::Critical, e.what());

		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
