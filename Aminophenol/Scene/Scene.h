
#ifndef SCENE_H
#define SCENE_H

#include "pch.h"

#include "Scene/Node.h"
#include "Maths/Color.h"

namespace Aminophenol {

	class AMINOPHENOL_API Scene final
		: public Node
	{
	public:

		Scene(const std::string name = "Scene", const Maths::Color backgroundColor = Maths::Color{ 0.0f, 0.0f, 0.0f, 1.0f });
		~Scene();

		// Getters
		const Maths::Color& getBackgroundColor() const;
		// Setters
		void setBackgroundColor(const Maths::Color& backgroundColor);

	private:
		
		Node* m_activeCamera{ nullptr };
		Maths::Color m_backgroundColor;
		
	};

} // namespace Aminophenol

#endif // SCENE_H
