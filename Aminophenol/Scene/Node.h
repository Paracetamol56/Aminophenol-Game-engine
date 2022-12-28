
#ifndef NODE_H
#define NODE_H

#include "pch.h"

#include "Utils/UUIDv4Generator.h"
#include "Scene/Component.h"

namespace Aminophenol {

	class AMINOPHENOL_API Node
	{
	public:

		Node(const std::string name = "New node", Node* parent = nullptr);
		~Node();

		// Accessors
		const Utils::UUID getUUID() const;
		const std::string& getName() const;
		void setName(const std::string& name);
		const Node* getParent() const;
		void enable();
		void disable();
		const bool isEnabled() const;
		const glm::mat4& getTransform() const;

		// Node hierarchy accessors
		Node& addChild(const std::string& name);
		Node& addChild(Node* child);
		void removeChild(const Utils::UUID& uuid);
		void detachChild(const Utils::UUID& uuid);
		Node& getChild(const Utils::UUID& uuid);

		// Component accessors
		// ToDo

	private:

		std::string m_name;
		const Utils::UUID m_uuid;
		Node* m_parent;
		bool m_enabled{ true };
		std::vector<Node*> m_children{};
		glm::mat4 m_transform; // TODO: Make a custom transform class
		// std::map<Utils::UUIDv4::UUID, Component> m_components{};

	};

} // namespace Aminophenol

#endif // NODE_H
