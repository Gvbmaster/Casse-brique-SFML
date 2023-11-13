#include "Ball.h"
#include <iostream>

Ball::Ball(float m_x, float m_y, float m_radius, float m_speed)
    : GameObject(m_x, m_y, m_radius * 2, m_radius * 2, 0.f, m_speed) {
}

Ball::~Ball() {
}

void getDirection(float& x, float& y, float angle) {
	x = cos(angle);
	y = sin(angle);
};
