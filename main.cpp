#include <SFML/Graphics.hpp>
#include "GameObject.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "GameObject Test");
    window.setFramerateLimit(60);

    GameObject Rect(100.f, 100.f, 50, 50);
    GameObject Circle(200.f, 200.f, 50, 50);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(Rect.getShape());
        window.display();
    }

    return 0;
}