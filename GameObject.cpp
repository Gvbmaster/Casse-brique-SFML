#include "GameObject.h"

GameObject::GameObject(float m_x, float m_y, float m_width, float m_height){
	GameObject::setSize(m_width, m_height);
	GameObject::setPosition(m_x, m_y);
	GameObject::setShape();
}

void GameObject::setSize(int m_width, int m_height) {
	this->m_width = m_width;
	this->m_height = m_height;

};

void GameObject::setPosition(float m_x, float m_y) {
	this->m_x = m_x;
	this->m_y = m_y;
	this->m_maxX = m_x + this->m_width;
	this->m_maxY = m_y + this->m_height;
};

void GameObject::setShape() {
	this->m_shape = new sf::RectangleShape(sf::Vector2f(this->m_width, this->m_height));
	this->m_shape->setPosition(this->m_x, this->m_y);
	this->m_shape->setFillColor(sf::Color::Magenta);
};

const sf::Shape& GameObject::getShape() {
	return * m_shape;
};

GameObject::~GameObject() {
	delete m_shape;
};