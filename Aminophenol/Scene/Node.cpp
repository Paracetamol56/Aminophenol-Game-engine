
#include "pch.h"
#include "Scene/Node.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	Node::Node(const std::string name, Node* parent)
		: NonCopyable()
		, m_name{ name }
		, m_uuid{ Utils::UUIDv4Generator32::getUUID() }
		, m_parent{ parent }
	{
		onCreate();
	}

	Node::~Node()
	{
		onDestroy();
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

	Node* Node::addChild(const std::string& name)
	{
		std::unique_ptr<Node> child = std::make_unique<Node>(name, this);
		m_children.push_back(std::move(child));
		return m_children.back().get();
	}

	Node* Node::addChild(std::unique_ptr<Node> child)
	{
		child->m_parent = this;
		m_children.push_back(std::move(child));
		return m_children.back().get();
	}
	
	void Node::removeChild(const Utils::UUID& uuid)
	{
		for (std::vector<std::unique_ptr<Node>>::iterator it = m_children.begin(); it != m_children.end(); ++it)
		{
			if ((*it)->getUUID() == uuid)
			{
				m_children.erase(it);
				return;
			}
		}
		Logger::log(LogLevel::Error, "Node::removeChild: Node with UUID %s not found.", uuid);
	}
	
	Node* Node::getChild(const Utils::UUID& uuid)
	{
		for (std::unique_ptr<Node>& child : m_children)
		{
			if (child->getUUID() == uuid)
			{
				return child.get();
			}
		}
		Logger::log(LogLevel::Error, "Node::getChild: Node with UUID %s not found.", uuid);
	}

	const size_t Node::getChildrenCount() const
	{
		return m_children.size();
	}

	const std::vector<Node*> Aminophenol::Node::getChildren() const
	{
		std::vector<Node*> children{};
		for (std::unique_ptr<Node> const& child : m_children)
		{
			children.push_back(child.get());
		}
		return children;
	}

	std::vector<std::unique_ptr<Node>>::iterator Aminophenol::Node::begin()
	{
		return m_children.begin();
	}

	std::vector<std::unique_ptr<Node>>::iterator Aminophenol::Node::end()
	{
		return m_children.end();
	}

	const std::vector<std::unique_ptr<Component>>& Node::getComponents() const
	{
		return m_components;
	}

	const size_t Node::getComponentCount() const
	{
		return m_components.size();
	}

	void Node::onAttach()
	{
		for (std::unique_ptr<Node> const& child : m_children)
		{
			child->onAttach();
		}
	}

	void Node::onStart()
	{
		for (std::unique_ptr<Component> const& component : m_components)
		{
			component->onStart();
		}
		for (std::unique_ptr<Node> const& child : m_children)
		{
			child->onStart();
		}
	}

	void Node::onFixedUpdate()
	{
		for (std::unique_ptr<Component> const& component : m_components)
		{
			component->onFixedUpdate();
		}
		for (std::unique_ptr<Node> const& child : m_children)
		{
			child->onFixedUpdate();
		}
	}

	void Node::onUpdate()
	{
		for (std::unique_ptr<Component> const& component : m_components)
		{
			component->onUpdate();
		}
		for (std::unique_ptr<Node> const& child : m_children)
		{
			child->onUpdate();
		}
	}

	void Node::onCreate()
	{}

	void Node::onDestroy()
	{}

} // namespace Aminophenol