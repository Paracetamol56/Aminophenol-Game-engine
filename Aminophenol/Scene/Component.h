
#ifndef COMPONENT_H
#define COMPONENT_H

#include "pch.h"

#include "Utils/NonCopyable.h"
#include "Utils/UUIDv4Generator.h"

namespace Aminophenol {

	class Node;

	class AMINOPHENOL_API Component : NonCopyable
	{
	public:

		Component(Node* node);
		virtual ~Component();

		// Accessors
		const Utils::UUID getUUID() const;
		Node* getNode() const;
		void enable();
		void disable();
		const bool isEnabled() const;

		virtual void onStart();
		virtual void onUpdate();
		virtual void onFixedUpdate();
		virtual void onDestroy();

	protected:

		const Utils::UUID m_uuid;
		Node* m_node;
		bool m_enabled{ true };

	};

} // namespace Aminophenol

#endif // COMPONENT_H
