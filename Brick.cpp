#include "Brick.h"


Brick::Brick(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed, int m_health)
    : GameObject(m_x, m_y, m_width, m_height, m_angle, m_speed)
{
    this->m_x = m_x;
    this->m_y = m_y;
    this->m_width = m_width;
    this->m_height = m_height;
    this->m_angle = m_angle;
    this->m_speed = m_speed;
    this->m_health = m_health;
}

Brick::~Brick() {}

void Brick::resetHealth(int m_health) {
    this->m_health = m_health;
}

void Brick::takeDamage() {
    this->m_health = this->m_health - 1;
}