
#ifndef RENDERER_H
#define RENDERER_H

#include "pch.h"

#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Pipeline/Pipeline.h"
#include "Rendering/Renderer/SubRenderer.h"

namespace Aminophenol
{

	class AMINOPHENOL_API Renderer
	{
	public:

		Renderer(const LogicalDevice& logicalDevice);
		~Renderer();

		void start();
		void update();

		template<typename T, typename... Args>
		T* AddSubRender(const Pipeline* pipelineStage, Args &&...args);
		
		template<typename T>
		T* GetSubRenderer() const;

		template<typename T>
		void RemoveSubRenderer();

	private:

		const LogicalDevice& m_logicalDevice;

		std::vector<std::unique_ptr<SubRenderer>> m_subRenderers;

	};

	template<typename T, typename... Args>
	T* Renderer::AddSubRender(const Pipeline* pipelineStage, Args &&...args)
	{
		m_subRenderers.push_back(std::make_unique<SubRenderer>(m_logicalDevice, args));
	}

	template<typename T>
	T* Renderer::GetSubRenderer() const
	{
		for (const auto& subRenderer : m_subRenderers)
		{
			if (dynamic_cast<T*>(subRenderer.get()))
			{
				return dynamic_cast<T*>(subRenderer.get());
			}
		}
	}

	template<typename T>
	void Renderer::RemoveSubRenderer()
	{
		for (auto it = m_subRenderers.begin(); it != m_subRenderers.end(); ++it)
		{
			if (dynamic_cast<T*>(it->get()))
			{
				m_subRenderers.erase(it);
				break;
			}
		}
	}

} // namespace Aminophenol

#endif // RENDERER_H
