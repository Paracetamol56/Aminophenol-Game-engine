
#include "pch.h"
#include "Scene/Node.h"

namespace Aminophenol {

	Node::Node(const std::string name, Node* parent)
		: m_name{ name }
		, m_parent{ parent }
	{}

	Node::~Node()
	{}

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

	const glm::mat4& Node::getTransform() const
	{
		return m_transform;
	}

} // namespace Aminophenol