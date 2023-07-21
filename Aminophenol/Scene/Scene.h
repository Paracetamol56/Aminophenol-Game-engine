
#ifndef SCENE_H
#define SCENE_H

#include "pch.h"

#include "Scene/Node.h"

namespace Aminophenol {

	class AMINOPHENOL_API Scene final
		: public Node
	{
	public:

		Scene(const std::string name = "Scene", const glm::vec4 backgroundColor = glm::vec4{ 0.0f, 0.0f, 0.0f, 1.0f });
		~Scene();

		// Getters
		const glm::vec4& getBackgroundColor() const;
		// Setters
		void setBackgroundColor(const glm::vec4& backgroundColor);

	private:
		
		Node* m_activeCamera{ nullptr };
		glm::vec4 m_backgroundColor;
		
	};

} // namespace Aminophenol

#endif // SCENE_H
