
#ifndef NODE_H
#define NODE_H

#include "pch.h"

#include "Utils/uuid_v4.h"
#include "Scene/Component.h"

namespace Aminophenol {

	class AMINOPHENOL_API Node
	{
	public:

		Node(const std::string name = "New node", Node* parent = nullptr);
		~Node();

		const std::string& getName() const;
		void setName(const std::string& name);
		const Node* getParent() const;
		const glm::mat4& getTransform() const;

	private:

		// std::map<Utils::UUIDv4::UUID, Component> m_components{};
		
		std::string m_name;
		Node* m_parent;
		glm::mat4 m_transform;

	};

} // namespace Aminophenol

#endif // NODE_H
