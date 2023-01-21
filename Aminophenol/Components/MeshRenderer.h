
#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "pch.h"
#include "Scene/Component.h"
#include "Rendering/Renderer/SubRenderer.h"

namespace Aminophenol {

	class MeshRenderer
		: public Component
		, public SubRenderer
	{
	public:

		MeshRenderer();
		~MeshRenderer();

	private:

		

	};

} // namespace Aminophenol

#endif // MESH_RENDERER_H
