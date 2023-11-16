#pragma once
#include "GameObject.h"
class Brick : public GameObject
{
public:
    Brick(float m_x, float m_y, float m_width, float m_height, float m_angle, float m_speed, int m_health);
    ~Brick();

    void resetHealth(int m_health);
    void takeDamage();
    virtual void onCollisionEnter(GameObject* other) override;
    bool isDestroyed();

private:
    bool m_destroyed = false;
    int m_health;
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    float m_angle;
    float m_speed;
};