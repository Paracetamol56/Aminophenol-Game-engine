#include "pch.h"
#include "MeshRenderer.h"

namespace Aminophenol {

	MeshRenderer::MeshRenderer(Node* node)
		: Component(node)
		//, SubRenderer()
	{
	}

	Aminophenol::MeshRenderer::MeshRenderer(Node* node, const std::shared_ptr<Mesh>& mesh)
		: Component(node)
		//, SubRenderer()
		, m_mesh(mesh)
	{
	}

	MeshRenderer::~MeshRenderer()
	{
	}

	void Aminophenol::MeshRenderer::setMesh(const std::shared_ptr<Mesh>& mesh)
	{
		m_mesh = mesh;
	}

	const std::shared_ptr<Mesh>& Aminophenol::MeshRenderer::getMesh() const
	{
		return std::shared_ptr<Mesh>();
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
