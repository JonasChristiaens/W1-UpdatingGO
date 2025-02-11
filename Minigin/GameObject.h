#pragma once
#include <memory>
#include <vector>
#include <typeindex>
#include "Transform.h"
#include "BaseComponent.h"

namespace dae
{
	class Texture2D;
	// todo: this should become final.
	class GameObject final
	{
	public:
		virtual void Update();
		virtual void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);


		template<typename ComponentType>
		ComponentType* GetComponent() const;


		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::shared_ptr<Texture2D> m_texture{};
		std::vector<std::pair<std::type_index, std::unique_ptr<BaseComponent>>> m_components;
	};

	template<typename ComponentType>
	ComponentType* GameObject::GetComponent() const
	{
		auto it = std::find_if(m_components.begin(), m_components.end(),
			[](const auto& pair) { return pair.first == typeid(ComponentType); });
		if (it != m_components.end())
		{
			return static_cast<ComponentType*>(it->second.get());
		}
		return nullptr;
	}


}
