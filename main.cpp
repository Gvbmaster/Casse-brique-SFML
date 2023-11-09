#include "GameObject.h"

int main() {
    int SCREENWIDTH = 800;
    int SCREENHEIGHT = 600;
    sf::Clock clock;
    float deltaTime = 0;
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "GameObject Test");
    sf::Vector2u windowSize = window.getSize();
    window.setFramerateLimit(60);

    GameObject Rect(100.f, 100.f, 50, 50, 0.f,600.f);
    GameObject Rect2(300.f, 100.f, 50, 50, 0.f, 0.f);
    GameObject Circle(200.f, 200.f, 100,20.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
            }
        }

        Rect.collision(Circle);
        Rect.isCollidingWithWindow(SCREENWIDTH,SCREENHEIGHT);
        Rect.collision(Rect2);
        Circle.collision(Rect);
        Rect.move(deltaTime);
        Circle.move(deltaTime);

        window.clear();
        window.draw(Circle.getShape());
        window.draw(Rect.getShape());
        window.draw(Rect2.getShape());
        window.display();
        deltaTime = clock.restart().asSeconds();
    }

    return 0;
}