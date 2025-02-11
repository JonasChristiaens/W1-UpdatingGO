#pragma once

class GameObject;
class BaseComponent
{
public:
	virtual void Update() = 0;
	virtual void Render(GameObject& gameObject) const = 0;
};