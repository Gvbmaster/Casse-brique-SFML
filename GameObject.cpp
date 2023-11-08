#include "GameObject.h"

GameObject::GameObject(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed){
	this->m_shape = new sf::RectangleShape(sf::Vector2f(m_width, m_height));

	GameObject::setSize(m_width, m_height);
	GameObject::setPosition(m_x, m_y);
	GameObject::setRotation(m_angle);
	
	this->m_speed = m_speed;
}

GameObject::GameObject(float m_x, float m_y, float m_radius, float m_speed) {
	this->m_shape = new sf::CircleShape(m_radius);

	GameObject::setRadius(m_radius);
	GameObject::setPosition(m_x, m_y);
	
	this->m_speed = m_speed;
}

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
}

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
	float newX = this->m_x + deltaTime * this->m_speed;
	float newY = this->m_y + deltaTime * this->m_speed;

	setPosition(newX, newY);
};

bool IsInside(int v, int vMin, int vMax) 
{
	return (v >= vMin) && (v <= vMax);
}

bool IsLineInside(int v1Min, int v1Max, int v2Min, int v2Max)
{
	return IsInside(v1Min, v2Min, v2Max) || IsInside(v1Max, v2Min, v2Max);
}

void GameObject::collision(GameObject& other) {
	if (IsLineInside(this->m_x, this->m_maxX, other.m_x, other.m_maxX)) {
		if (IsLineInside(this->m_y, this->m_maxY, other.m_y, other.m_maxY)) {
			this->m_speed *=-1;
		}
	}
};

GameObject::~GameObject() {
	delete m_shape;
};