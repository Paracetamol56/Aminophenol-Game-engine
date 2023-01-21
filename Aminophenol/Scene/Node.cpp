
#include "pch.h"
#include "Scene/Node.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	Node::Node(const std::string name, Node* parent)
		: m_name{ name }
		, m_uuid{ Utils::UUIDv4Generator32::getUUID() }
		, m_parent{ parent }
	{}

	Node::~Node()
	{
		for (Node* child : m_children)
		{
			delete child;
		}
	}

	const Utils::UUID Aminophenol::Node::getUUID() const
	{
		return m_uuid;
	}

	const std::string& Node::getName() const
	{
		return m_name;
	}

	void Node::setName(const std::string& name)
	{
		m_name = name;
	}

	const Node* Node::getParent() const
	{
		return m_parent;
	}

	void Node::enable()
	{
		m_enabled = true;
	}

	void Node::disable()
	{
		m_enabled = false;
	}

	const bool Node::isEnabled() const
	{
		return m_enabled;
	}

	const glm::mat4& Node::getTransform() const
	{
		return m_transform;
	}

	Node& Node::addChild(const std::string& name)
	{
		m_children.push_back(new Node(name, this));
		return *m_children.back();
	}

	Node& Node::addChild(Node* child)
	{
		m_children.push_back(child);
		return *m_children.back();
	}
	
	void Node::removeChild(const Utils::UUID& uuid)
	{
		for (std::vector<Node*>::iterator it = m_children.begin(); it != m_children.end(); ++it)
		{
			if ((*it)->getUUID() == uuid)
			{
				delete* it;
				m_children.erase(it);
				return;
			}
		}
		Logger::log(LogLevel::Error, "Node::removeChild: Node with UUID %s not found.", uuid);
	}

	void Aminophenol::Node::detachChild(const Utils::UUID& uuid)
	{
		for (std::vector<Node*>::iterator it = m_children.begin(); it != m_children.end(); ++it)
		{
			if ((*it)->getUUID() == uuid)
			{
				m_parent->addChild(*it);
				m_children.erase(it);
				return;
			}
		}
		Logger::log(LogLevel::Error, "Node::detachChild: Node with UUID %s not found.", uuid);
	}
	
	Node& Node::getChild(const Utils::UUID& uuid)
	{
		for (Node* child : m_children)
		{
			if (child->getUUID() == uuid)
			{
				return *child;
			}
		}
		Logger::log(LogLevel::Error, "Node::getChild: Node with UUID %s not found.", uuid);
	}

	const std::vector<std::shared_ptr<Component>>& Node::getComponents() const
	{
		return m_components;
	}

	const size_t Node::getComponentCount() const
	{
		return m_components.size();
	}

} // namespace Aminophenol