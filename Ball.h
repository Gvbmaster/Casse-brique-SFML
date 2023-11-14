#pragma once
#include "GameObject.h"
class Ball : public GameObject
{
public:
	Ball(float m_x, float m_y, float m_radius, float m_speed);
	~Ball();

	void setDirection(sf::Vector2f direction);
	sf::Vector2f getDirection() const;
};