#include "GameObject.h"
#include <iostream>

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
	return *m_shape;
}
void GameObject::move(float deltaTime) {
	float moveDistance = m_speed * deltaTime;
	float newX = m_x + m_direction.x * moveDistance;
	float newY = m_y + m_direction.y * moveDistance;
	setPosition(newX, newY);
};

void GameObject::moveTestMouse(sf::Vector2i mousePosition) {
	float moveDistance = m_speed;
	float newX = m_x;
	float newY = m_y;
	if (mousePosition.x > m_x) {
		newX = m_x + moveDistance;
	}
	else if (mousePosition.x < m_x) {
		newX = m_x - moveDistance;
	}
	if (mousePosition.y > m_y) {
		newY = m_y + moveDistance;
	}
	else if (mousePosition.y < m_y) {
		newY = m_y - moveDistance;
	}
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

//void GameObject::collision(GameObject& other) {
//	if (IsLineInside(this->m_x, this->m_maxX, other.m_x, other.m_maxX)) {
//		if (IsLineInside(this->m_y, this->m_maxY, other.m_y, other.m_maxY)) {
//			this->m_direction = -m_direction;
//			std::cout << "Collision faite "<< std::endl;
//		}
//	}
//};

void GameObject::collision(GameObject& other) {
	float dx = other.m_x - m_x;
	float dy = other.m_y - m_y;

	// Calculer la somme des demi-largeurs et demi-hauteurs
	float combinedHalfWidth = (m_width + other.m_width) / 2.0f;
	float combinedHalfHeight = (m_height + other.m_height) / 2.0f;

	// Calculer la différence absolue entre les centres
	float offsetX = std::abs(dx) - combinedHalfWidth;
	float offsetY = std::abs(dy) - combinedHalfHeight;

	// Vérifier s'il y a collision
	if (offsetX < 0 && offsetY < 0) {

		if (offsetX > offsetY) {
			// Collision selon l'axe x
			if (dx > 0) {
				m_direction.x = -std::abs(m_direction.x);
				std::cout << "Collision sur la gauche" << std::endl;
			}
			else {
				m_direction.x = std::abs(m_direction.x);
				std::cout << "Collision sur la droite" << std::endl;
			}
		}
		else {
			// Collision selon l'axe y
			if (dy > 0) {
				m_direction.y = -std::abs(m_direction.y);
				std::cout << "Collision en haut" << std::endl;
			}
			else {
				m_direction.y = std::abs(m_direction.y);
				std::cout << "Collision en bas" << std::endl;
			}
		}
	}
}

void GameObject::isCollidingWithWindow(int SCREENWIDTH, int SCREENHEIGHT) {
	if (m_x < 0 || m_x + m_width > SCREENWIDTH) {
		this->m_direction.x = -m_direction.x;
	}

	if (m_y < 0 || m_y + m_height > SCREENHEIGHT) {
		this->m_direction.y = -m_direction.y;
	}
}

bool GameObject::stillColliding(GameObject& other) {
	float dx = other.m_x - m_x;
	float dy = other.m_y - m_y;

	float combinedHalfWidth = (m_width + other.m_width) / 2.0f;
	float combinedHalfHeight = (m_height + other.m_height) / 2.0f;

	float offsetX = std::abs(dx) - combinedHalfWidth;
	float offsetY = std::abs(dy) - combinedHalfHeight;

	return (offsetX < 0 && offsetY < 0);
}

GameObject::~GameObject() {
	delete m_shape;
};