
#ifndef COMPONENT_H
#define COMPONENT_H

#include "pch.h"

#include "Utils/UUIDv4Generator.h"

namespace Aminophenol {

	class Node;

	class AMINOPHENOL_API Component
	{
	public:

		Component(const Node* node);
		virtual ~Component();

		// Accessors
		const Utils::UUID getUUID() const;
		const Node* getNode() const;
		void enable();
		void disable();
		const bool isEnabled() const;

		virtual void start();
		virtual void update();
		virtual void fixedUpdate();

	protected:

		const Utils::UUID m_uuid;
		const Node* m_node;
		bool m_enabled{ true };

	};

} // namespace Aminophenol

#endif // COMPONENT_H
