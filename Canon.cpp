#include "Canon.h"
#include <iostream>

Canon::Canon(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed)
    : GameObject(m_x, m_y, m_width, m_height, m_angle, m_speed) {
}

Canon::~Canon() {
}

void Canon::setDirection(sf::RenderWindow& window) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f objectPosition = m_shape->getPosition();

	m_direction = sf::Vector2f(mousePosition.x, mousePosition.y) - objectPosition;

	float length = std::sqrt(m_direction.x * m_direction.x + m_direction.y * m_direction.y);
	if (length != 0) {
		m_direction /= length;
	}

	float angleRadians = std::atan2(m_direction.y, m_direction.x);
	float angleDegrees = angleRadians * 180.0f / 3.14159265f;

	const float minAngle = -170.0f;
	const float maxAngle = -10.0f;

	if (angleDegrees >= minAngle && angleDegrees <= maxAngle) {

		std::cout << angleDegrees << std::endl;
		setRotation(angleDegrees);
	}
}

void Canon::moveTowardsMouse(sf::RenderWindow& window) {
    setDirection(window);
    setOrigin(m_width/4, m_height/2);
}