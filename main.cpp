#include "GameObject.h"
#include "Canon.h"
#include <iostream>

int main() {
    int SCREENWIDTH = 800;
    int SCREENHEIGHT = 600;
    sf::Clock clock;
    float deltaTime = 0;
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Test");
    sf::Vector2u windowSize = window.getSize();
    Canon oCanon(375.f, 525.f, 100, 50, 0.f, 5.f);
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Obtention de la position de la souris
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        oCanon.moveTowardsMouse(window);

        window.clear();

        window.draw(oCanon.getShape());

        window.display();

        deltaTime = clock.restart().asSeconds();
    }

    return 0;
}