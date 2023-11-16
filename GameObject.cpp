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

sf::Vector2f GameObject::getPosition() const {
	return sf::Vector2f(m_x, m_y);
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

void GameObject::getOrigin(float m_x, float m_y) {
	this->m_shape->getOrigin();
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

bool GameObject::checkCollision(GameObject& other) {
	float dx = other.m_x - m_x;
	float dy = other.m_y - m_y;

	float combinedHalfWidth = (m_width + other.m_width) / 2.0f;
	float combinedHalfHeight = (m_height + other.m_height) / 2.0f;

	float offsetX = std::abs(dx) - combinedHalfWidth;
	float offsetY = std::abs(dy) - combinedHalfHeight;

	bool collision = offsetX < 0 && offsetY < 0;
	auto it = std::find(collidingObjects.begin(), collidingObjects.end(), &other);
	bool alreadyColliding = it != collidingObjects.end();

	if (collision) 
	{
		if (alreadyColliding == false)
		{
			collidingObjects.push_back(&other);
			onCollisionEnter(&other);
			other.onCollisionEnter(this);
		}
		else 
		{
			onCollisionStay(&other);
			other.onCollisionStay(this);
		}
	}
	else {
		if (alreadyColliding) 
		{
			collidingObjects.erase(it);
			onCollisionExit(&other);
			other.onCollisionExit(this);
		}
	}

	return collision;
}


void GameObject::bounce() {
	m_direction.y = -m_direction.y;
}

void GameObject::isCollidingWithWindow(int SCREENWIDTH, int SCREENHEIGHT) {
	if (m_x < 0 || m_x + m_width > SCREENWIDTH) {
		this->m_direction.x = -m_direction.x;
	}

	if (m_y < 0 ) {
		this->m_direction.y = -m_direction.y;
	}
}

void GameObject::onCollisionEnter(GameObject* other) {
	std::cout << "Collision avec " << typeid(*other).name() << " détectée." << std::endl;
}

void GameObject::onCollisionStay(GameObject* other) {
	std::cout << "Collision continue avec " << typeid(*other).name() << "." << std::endl;
}

void GameObject::onCollisionExit(GameObject* other) {
	std::cout << "Fin de la collision avec " << typeid(*other).name() << "." << std::endl;
}


GameObject::~GameObject() {
	delete m_shape;
};