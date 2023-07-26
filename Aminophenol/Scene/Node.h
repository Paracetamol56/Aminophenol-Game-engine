
#ifndef NODE_H
#define NODE_H

#include "pch.h"

#include "Utils/NonCopyable.h"
#include "Utils/UUIDv4Generator.h"
#include "Scene/Component.h"

#include "Components/Camera.h"
#include "Components/MeshRenderer.h"

namespace Aminophenol {

	class AMINOPHENOL_API Node : NonCopyable
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
		Node* addChild(const std::string& name);
		Node* addChild(const std::unique_ptr<Node> child);
		void removeChild(const Utils::UUID& uuid);
		Node* getChild(const Utils::UUID& uuid);
		const std::vector<Node*> getChildren() const;
		const size_t getChildrenCount() const;
		std::vector<std::unique_ptr<Node>>::iterator begin();
		std::vector<std::unique_ptr<Node>>::iterator end();

		// Component accessors
		template<typename T, typename... Args>
		T* addComponent(Args &&...args);
		 const std::vector<std::unique_ptr<Component>>& getComponents() const;
		const size_t getComponentCount() const;
		template<typename T>
		T* getComponentOfType() const;
		template<typename T>
		std::vector<T*> getComponentsOfType() const;
		template<typename T>
		T* getComponent(const Utils::UUID& uuid) const;
		template<typename T>
		void removeComponent(const Utils::UUID& uuid);
		
		// Events
		void onAttach();
		void onStart();
		void onFixedUpdate();
		void onUpdate();

	protected:
		
		// Events
		virtual void onCreate();
		virtual void onDestroy();

	private:

		std::string m_name;
		const Utils::UUID m_uuid;
		Node* m_parent;
		bool m_enabled{ true };
		glm::mat4 m_transform; // TODO: Make a custom transform class
		std::vector<std::unique_ptr<Node>> m_children;
		std::vector<std::unique_ptr<Component>> m_components;
		
	};
	
	template<typename T, typename... Args>
	T* Node::addComponent(Args &&...args)
	{
		static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
		std::unique_ptr<Component> component = std::make_unique<T>(this, std::forward<Args>(args)...);
		m_components.push_back(std::move(component));
		return static_cast<T*>(m_components.back().get());
	}

	template<typename T>
	T* Node::getComponentOfType() const
	{
		for (std::unique_ptr<Component> const& component : m_components)
		{
			auto castedComponent = dynamic_cast<T*>(component.get());
			if (castedComponent)
			{
				return castedComponent;
			}
		}
		return nullptr;
	}

	template<typename T>
	inline std::vector<T*> Aminophenol::Node::getComponentsOfType() const
	{
		std::vector<T*> components;
		for (std::unique_ptr<Component> const& component : m_components)
		{
			auto castedComponent = dynamic_cast<T*>(component.get());
			if (castedComponent)
			{
				components.push_back(castedComponent);
			}
		}
		return components;
	}

	template<typename T>
	T* Node::getComponent(const Utils::UUID& uuid) const
	{
		for (std::unique_ptr<Component> const& component : m_components)
		{
			if (component->getUUID() == uuid)
			{
				return component.get();
			}
		}
		return nullptr;
	}
	
	template<typename T>
	void Node::removeComponent(const Utils::UUID& uuid)
	{
		for (std::vector<std::unique_ptr<Component>>::iterator it = m_components.begin(); it != m_components.end(); ++it)
		{
			if ((*it)->getUUID() == uuid)
			{
				m_components.erase(it);
				return;
			}
		}
	}

} // namespace Aminophenol

#endif // NODE_H
