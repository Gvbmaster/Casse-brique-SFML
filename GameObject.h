#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed);
	GameObject(float m_x, float m_y, float m_radius, float m_speed);
	~GameObject();

	void setPosition(float m_x, float m_y);
	void setSize(int m_width, int m_height);
	void setRadius(float m_radius);
	void setAngle(float m_angle);
	void setRotation(float m_angle);
	void setOrigin(float m_x, float m_y);
	void move(float deltaTime);
	void collision(GameObject& other);
	const sf::Shape& getShape();

private:
	float m_x;
	float m_y;
	float m_maxX;
	float m_maxY;
	float m_radius;
	float m_angle;
	float m_speed;
	int m_width;
	int m_height;
	sf::Shape* m_shape;
};

