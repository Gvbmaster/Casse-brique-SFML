#pragma once
#include "GameObject.h"
#include "Ball.h"

class Canon : public GameObject {
public:
    Canon(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed);
    ~Canon();

    void setDirection(sf::RenderWindow& window);
    void moveTowardsMouse(sf::RenderWindow& window);
    bool isFiring() const;
    void shoot(Ball& ball);
    void stopFiring();
private:
    bool Firing;
};

