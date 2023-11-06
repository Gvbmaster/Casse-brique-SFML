#include "GameObject.h"

GameObject::GameObject(int m_x, int m_y, int m_width, int m_height){}

void GameObject::setSize(int m_width, int m_height) {
	this->m_width = m_width;
	this->m_height = m_height;

};

void GameObject::setPosition(int m_x, int m_y) {
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