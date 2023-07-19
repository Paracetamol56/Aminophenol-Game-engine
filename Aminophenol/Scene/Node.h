
#ifndef NODE_H
#define NODE_H

#include "pch.h"

#include "Utils/UUIDv4Generator.h"
#include "Scene/Component.h"
#include "Components/MeshRenderer.h"

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
		std::vector<Node*> getChildren() const;
		std::vector<Node*>::iterator begin();
		std::vector<Node*>::iterator end();

		// Component accessors
		template<typename T, typename... Args>
		T* addComponent(Args &&...args);
		const std::vector<std::shared_ptr<Component>>& getComponents() const;
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
		virtual void onAttach();
		virtual void onFixedUpdate();
		virtual void onUpdate();

	protected:
		
		// Events
		virtual void onCreate();
		virtual void onDestroy();

	private:

		std::string m_name;
		const Utils::UUID m_uuid;
		Node* m_parent;
		bool m_enabled{ true };
		std::vector<Node*> m_children{};
		glm::mat4 m_transform; // ToDo: Make a custom transform class
		std::vector<std::shared_ptr<Component>> m_components;
		
	};
	
	template<typename T, typename... Args>
	T* Node::addComponent(Args &&...args)
	{
		static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
		T* component = new T(this, std::forward<Args>(args)...);
		m_components.push_back(std::unique_ptr<T>(component));
		return component;
	}

	template<typename T>
	T* Node::getComponentOfType() const
	{
		for (const std::unique_ptr<Component>& component : m_components)
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
		for (const std::shared_ptr<Component>& component : m_components)
		{
			if (dynamic_cast<T*>(component.get()))
			{
				components.push_back(dynamic_cast<T*>(component.get()));
			}
		}
		return components;
	}

	template<typename T>
	T* Node::getComponent(const Utils::UUID& uuid) const
	{
		for (const std::unique_ptr<Component>& component : m_components)
		{
			if (component->getUUID() == uuid)
			{
				return dynamic_cast<T*>(component.get());
			}
		}
		return nullptr;
	}
	
	template<typename T>
	void Node::removeComponent(const Utils::UUID& uuid)
	{
		for (auto it = m_components.begin(); it != m_components.end(); ++it)
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
