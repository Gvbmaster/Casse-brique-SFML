#pragma once
#include "GameObject.h"
#include "Canon.h"
#include "Ball.h"
#include "Brick.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class GameManager {
public:
    GameManager();
    ~GameManager();

    void run();

private:
    sf::RenderWindow window;
    Canon oCanon;
    Ball oBall;
    std::vector<Brick*> bricks;

    void initialize();
    void processEvents();
    void update(float deltaTime);
    void render();
};