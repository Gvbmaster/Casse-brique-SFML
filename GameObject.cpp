#include "GameObject.h"

GameObject::GameObject(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed) {
	this->m_shape = new sf::RectangleShape(sf::Vector2f(m_width, m_height));

	GameObject::setSize(m_width, m_height);
	GameObject::setPosition(m_x, m_y);
	GameObject::setRotation(m_angle);
	float angleInRadians = m_angle * 3.14159265f / 180;
	m_direction.x = std::cos(angleInRadians);
	m_direction.y = std::sin(angleInRadians);


	this->m_speed = m_speed;
};

GameObject::GameObject(float m_x, float m_y, float m_radius, float m_speed) {
	this->m_shape = new sf::CircleShape(m_radius);

	GameObject::setRadius(m_radius);
	GameObject::setPosition(m_x, m_y);

	this->m_speed = m_speed;
};

void GameObject::setSize(int m_width, int m_height) {
	this->m_width = m_width;
	this->m_height = m_height;
};

void GameObject::setRadius(float m_radius) {
	this->m_radius = m_radius;
};

void GameObject::setPosition(float m_x, float m_y) {
	this->m_x = m_x;
	this->m_y = m_y;
	this->m_maxX = m_x + this->m_width;
	this->m_maxY = m_y + this->m_height;

	this->m_shape->setPosition(this->m_x, this->m_y);
};

void GameObject::setRotation(float m_angle) {
	this->setAngle(m_angle);
	this->m_shape->setRotation(m_angle);
};

void GameObject::setAngle(float m_angle) {
	this->m_angle = m_angle;
};

void GameObject::setOrigin(float m_x, float m_y) {
	this->m_shape->setOrigin(m_x, m_y);
};

const sf::Shape& GameObject::getShape() {
	return * m_shape;
};
void GameObject::move(float deltaTime) {
	float moveDistance = m_speed * deltaTime;
	float newX = m_x + m_direction.x * moveDistance;
	float newY = m_y + m_direction.y * moveDistance;
	setPosition(newX, newY);
};

bool IsInside(int v, int vMin, int vMax)
{
	return (v >= vMin) && (v <= vMax);
};

bool IsLineInside(int v1Min, int v1Max, int v2Min, int v2Max)
{
	return IsInside(v1Min, v2Min, v2Max) || IsInside(v1Max, v2Min, v2Max);
};

void GameObject::collision(GameObject& other) {
	if (IsLineInside(this->m_x, this->m_maxX, other.m_x, other.m_maxX)) {
		if (IsLineInside(this->m_y, this->m_maxY, other.m_y, other.m_maxY)) {
			this->m_speed *=-1;
		}
	}
};

void GameObject::isCollidingWithWindow(int SCREENWIDTH, int SCREENHEIGHT) {
	if (m_x < 0 || m_x + m_width > SCREENWIDTH) {
		m_direction.x = -m_direction.x;
	}

	if (m_y < 0 || m_y + m_height > SCREENHEIGHT) {
		m_direction.y = -m_direction.y;
	}
}

GameObject::~GameObject() {
	delete m_shape;
};