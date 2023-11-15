#include "GameObject.h"
#include "Canon.h"
#include "Ball.h"
#include "Brick.h"
#include <iostream>

int main() {
    int SCREENWIDTH = 800;
    int SCREENHEIGHT = 600;
    sf::Clock clock;
    float deltaTime = 0;
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Test");
    sf::Vector2u windowSize = window.getSize();
    window.setFramerateLimit(60);
    Canon oCanon(SCREENWIDTH/2, 525.f, 100, 70, 0.f, 5.f);
    Ball oBall(-900,0,10.f,300.f);
    std::vector<Brick*> bricks;

    int line = 5;
    int bricksPerLine = 8;
    int marginX = 15;
    int marginY = 15;
    for (int y = 0; y < line; ++y) {
        for (int x = 0; x < bricksPerLine; ++x) {
            bricks.push_back(new Brick(marginX + x * 100, marginY + y * 50, 75, 25, 0.f, 0.f, 3));
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        oCanon.moveTowardsMouse(window);

        // Vérifiez si la balle est tirée
        if (!oCanon.isFiring()) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                oCanon.shoot(oBall);
            }
        }
        else {
            if (oBall.getPosition().y > SCREENHEIGHT) {
                oCanon.stopFiring();
            }
        }
        oBall.move(deltaTime);
        oBall.isCollidingWithWindow(SCREENWIDTH, SCREENHEIGHT);

        window.clear();
        window.draw(oCanon.getShape());
        window.draw(oBall.getShape());

        for (int i = 0; i < bricks.size(); ++i) {
            oBall.collision(*bricks[i]);
            window.draw(bricks[i]->getShape());

        }

        window.display();

        deltaTime = clock.restart().asSeconds();
    }

    for (int i = 0; i < bricks.size(); ++i) {
        delete bricks[i];
    }

    return 0;
}