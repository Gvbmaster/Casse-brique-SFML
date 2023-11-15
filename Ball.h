#pragma once
#include "GameObject.h"
class Ball : public GameObject
{
public:
	Ball(float m_x, float m_y, float m_radius, float m_speed);
	~Ball();

	void setDirection(sf::Vector2f direction);
	virtual void onCollisionEnter(GameObject* other) override;
	virtual void onCollisionStay(GameObject* other) override;
	virtual void onCollisionExit(GameObject* other) override;
};