#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float m_x, float m_y, float m_width, float m_height);
	GameObject(float m_x, float m_y, float m_radius);
	~GameObject();

	void setPosition(float m_x, float m_y);
	void setSize(int m_width, int m_height);
	void setShape();
	const sf::Shape& getShape();

private:
	float m_x;
	float m_y;
	float m_maxX;
	float m_maxY;
	int m_width;
	int m_height;
	sf::Shape* m_shape;
};

