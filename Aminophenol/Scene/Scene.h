
#ifndef SCENE_H
#define SCENE_H

#include "pch.h"

#include "Node.h"
#include "Components/Camera.h"
#include "Maths/Color.h"

namespace Aminophenol {

	class AMINOPHENOL_API Scene final
		: public Node
	{
	public:

		Scene(const std::string name = "Scene", const Maths::Color backgroundColor = Maths::Color{ 0.0f, 0.0f, 0.0f, 1.0f });
		~Scene();

		
		Camera* getActiveCamera() const;
		const Maths::Color& getBackgroundColor() const;
		
		void setActiveCamera(Camera* activeCamera);
		void setBackgroundColor(const Maths::Color& backgroundColor);

	private:
		
		Camera* m_activeCamera{ nullptr };
		Maths::Color m_backgroundColor;
		
	};

} // namespace Aminophenol

#endif // SCENE_H
