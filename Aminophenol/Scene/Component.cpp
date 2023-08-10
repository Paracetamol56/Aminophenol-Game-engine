
#include "pch.h"
#include "Component.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	Component::Component(Node* node)
		: m_uuid{ Utils::UUIDv4Generator32::getUUID() }
		, m_node{ node }
	{}

	Component::~Component()
	{
		onDestroy();
	}

	const Utils::UUID Component::getUUID() const
	{
		return m_uuid;
	}
	
	Node* Component::getNode() const
	{
		return m_node;
	}

	void Component::enable()
	{
		m_enabled = true;
	}
	
	void Component::disable()
	{
		m_enabled = false;
	}
	
	const bool Component::isEnabled() const
	{
		return m_enabled;
	}

	void Component::onStart()
	{}
	
	void Component::onUpdate()
	{}
	
	void Component::onFixedUpdate()
	{}

	void Component::onDestroy()
	{}

} // namespace Aminophenol
