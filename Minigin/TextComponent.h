#pragma once
#include <string>
#include <memory>
#include "BaseComponent.h"
#include "Transform.h"

namespace dae
{
	class Font;
	class Texture2D;
	class GameObject;
	class TextComponent final : public BaseComponent
	{
	public:
		void Update() override;
		//void Render(GameObject& gameObject) const override;

		void SetText(const std::string& text);
		void SetPosition(float x, float y);

	private:
		bool m_needsUpdate;
		std::string m_text;
		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture2D> m_textTexture;
	};
}

