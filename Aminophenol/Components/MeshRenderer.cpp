#include "pch.h"
#include "MeshRenderer.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	MeshRenderer::MeshRenderer(Node* node)
		: Component(node)
	{}

	MeshRenderer::MeshRenderer(Node* node, const std::shared_ptr<Mesh>& mesh)
		: Component(node)
		, m_mesh(mesh)
	{}

	MeshRenderer::~MeshRenderer()
	{
		m_mesh.reset();
	}

	void Aminophenol::MeshRenderer::setMesh(const std::shared_ptr<Mesh>& mesh)
	{
		m_mesh = mesh;
	}

	const std::shared_ptr<Mesh>& Aminophenol::MeshRenderer::getMesh() const
	{
		return m_mesh;
	}

	void Aminophenol::MeshRenderer::renderMesh(VkCommandBuffer commandBuffer)
	{
		if (m_mesh == nullptr)
		{
			return;
		}

		m_mesh->bind(commandBuffer);
		m_mesh->draw(commandBuffer);
	}

} // namespace Aminophenol
