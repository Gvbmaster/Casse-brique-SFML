#include "GameObject.h"

GameObject::GameObject(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed){
	GameObject::setSize(m_width, m_height);
	GameObject::setPosition(m_x, m_y);
	GameObject::setShapeRect();
	GameObject::setRotation(m_angle);
	GameObject::move(m_x, m_y, m_speed, m_speed);
}

GameObject::GameObject(float m_x, float m_y, float m_radius) {
	GameObject::setRadius(m_radius);
	GameObject::setPosition(m_x, m_y);
	GameObject::setShapeCircle();
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
};

void GameObject::setShapeRect() {
	this->m_shape = new sf::RectangleShape(sf::Vector2f(this->m_width, this->m_height));
	this->m_shape->setPosition(this->m_x, this->m_y);
	this->m_shape->setFillColor(sf::Color::Magenta);
};

void GameObject::setShapeCircle() {
	this->m_shape = new sf::CircleShape(this->m_radius);
	this->m_shape->setPosition(this->m_x, this->m_y);
	this->m_shape->setFillColor(sf::Color::Magenta);
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
void GameObject::move(float m_x, float m_y, float deltaTime, float m_speed) {
	this->m_x += deltaTime * m_speed;
	this->m_y += deltaTime * m_speed;
	this->m_maxX += m_x;
	this->m_maxY += m_y;
	this->m_shape->setPosition(this->m_x, this->m_y);
};
GameObject::~GameObject() {
	delete m_shape;
};