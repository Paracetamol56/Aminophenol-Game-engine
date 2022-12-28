
#ifndef SCENE_H
#define SCENE_H

#include "pch.h"

#include "Scene/Node.h"

namespace Aminophenol {

	class AMINOPHENOL_API Scene
		: public Node
	{
	public:

		Scene(const std::string name = "Scene");
		~Scene();

	private:
		
		Node* m_activeCamera{ nullptr };
		
	};

} // namespace Aminophenol

#endif // SCENE_H
