#include "GameObject.h"
#include <iostream>

int main() {
    int SCREENWIDTH = 800;
    int SCREENHEIGHT = 600;
    sf::Clock clock;
    float deltaTime = 0;
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "GameObject Test");
    sf::Vector2u windowSize = window.getSize();
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
            }
        }
        //obtention de la position de la souris
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        //affichage de la collision avec le coté pour débugage
        /*std::cout << "Collision à gauche : " << mousePosition.x << ", " << mousePosition.y << std::endl;*/


        //Rect.isCollidingWithWindow(SCREENWIDTH,SCREENHEIGHT);
        /*Circle.collision(Rect);*/


        /*Rect.setPosition(mousePosition.x, mousePosition.y);*/
        /*if (Rect.stillColliding(Rect2)) {
            std::cout << "Rect est toujours en collision avec Rect2" << std::endl;
        }
        else {
            std::cout << "Rect n'est plus en collision avec Rect2" << std::endl;
        }*/

        //Rect.moveTestMouse(mousePosition);
        /*Circle.move(deltaTime);*/

        window.clear();
        window.display();
        deltaTime = clock.restart().asSeconds();
    }

    return 0;
}