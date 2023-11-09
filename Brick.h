#pragma once
#include "GameObject.h"
class Brick : public GameObject
{
public:
	Brick(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed);
	~Brick();
private:
	int m_health;
	float m_x;
	float m_y;
	float m_width;
	float m_height;
	float m_angle;
	float m_speed;
};

