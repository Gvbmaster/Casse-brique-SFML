#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>

class GameObject
{
public:
	GameObject(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed);
	GameObject(float m_x, float m_y, float m_radius, float m_speed);
	~GameObject();

	void setPosition(float m_x, float m_y);
	sf::Vector2f getPosition() const;
	void setSize(int m_width, int m_height);
	void setRadius(float m_radius);
	void setAngle(float m_angle);
	void setRotation(float m_angle);
	void setOrigin(float m_x, float m_y);
	void getOrigin(float m_x, float m_y);
	void move(float deltaTime);
	void collision(GameObject& other);
	void isCollidingWithWindow(int SCREENWIDTH, int SCREENHEIGHT);
	const sf::Shape& getShape();
	bool stillColliding(GameObject& other);

protected:
	float m_x;
	float m_y;
	float m_maxX;
	float m_maxY;
	float m_radius;
	float m_angle;
	float m_speed;
	float m_directionX;
	float m_directionY;

	int m_width;
	int m_height;
	sf::Vector2f m_direction;
	sf::Shape* m_shape;
};

