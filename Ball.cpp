#include "Ball.h"
#include <iostream>

Ball::Ball(float m_x, float m_y, float m_radius, float m_speed)
    : GameObject(m_x, m_y, m_radius * 2, m_speed) {
}

Ball::~Ball() {
}

void Ball::setDirection(sf::Vector2f direction)
{
    m_direction = direction;
}

sf::Vector2f Ball::getDirection() const
{
    return m_direction;
}