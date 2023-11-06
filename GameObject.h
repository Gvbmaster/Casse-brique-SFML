#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(int m_x, int m_y, int m_width, int m_height);

	~GameObject();

	void setPosition(int m_x, int m_y);

	void setSize(int m_width, int m_height);

	void setShape();

private:
	int m_x;
	int m_y;
	int m_maxX;
	int m_maxY;
	int m_width;
	int m_height;
	sf::Shape* m_shape;
};

