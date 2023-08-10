
#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "Rendering/Renderer/SubRenderer.h"
#include "Scene/Component.h"
#include "Scene/Node.h"
#include "Mesh/Mesh.h"

namespace Aminophenol {
	
	class MeshRenderer final
		: public Component
	{
	public:

		MeshRenderer(Node* node);
		MeshRenderer(Node* node, const std::shared_ptr<Mesh>& mesh);
		~MeshRenderer();

		// Mesh accessors
		void setMesh(const std::shared_ptr<Mesh>& mesh);
		const std::shared_ptr<Mesh>& getMesh() const;

		void renderMesh(VkCommandBuffer commandBuffer);

	private:

		std::shared_ptr<Mesh> m_mesh;

	};

} // namespace Aminophenol

#endif // MESH_RENDERER_H
