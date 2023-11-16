#include "GameManager.h"

GameManager::GameManager()
    : window(sf::VideoMode(800, 600), "Test"), oCanon(800 / 2, 525.f, 100, 70, 0.f, 5.f),
    oBall(-900, 0, 10.f, 300.f) {
    initialize();
}

GameManager::~GameManager() {
    for (Brick* brick : bricks) {
        delete brick;
    }
}

void GameManager::initialize() {
    window.setFramerateLimit(60);

    int line = 5;
    int bricksPerLine = 8;
    int marginX = 15;
    int marginY = 15;
    for (int y = 0; y < line; ++y) {
        for (int x = 0; x < bricksPerLine; ++x) {
            bricks.push_back(new Brick(marginX + x * 100, marginY + y * 50, 75, 25, 0.f, 0.f, 3));
        }
    }
}

void GameManager::run() {
    sf::Clock clock;
    float deltaTime = 0;

    while (window.isOpen()) {
        processEvents();
        update(deltaTime);
        render();
        deltaTime = clock.restart().asSeconds();
    }
}

void GameManager::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void GameManager::update(float deltaTime) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    oCanon.moveTowardsMouse(window);

    if (!oCanon.isFiring()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            oCanon.shoot(oBall);
        }
    }
    else {
        if (oBall.getPosition().y > window.getSize().y) {
            oCanon.stopFiring();
        }
    }

    oBall.move(deltaTime);
    oBall.isCollidingWithWindow(window.getSize().x, window.getSize().y);

    for (Brick* brick : bricks) {
        oBall.checkCollision(*brick);
        if (brick->isDestroyed()) {
            bricks.erase(std::remove(bricks.begin(), bricks.end(), brick), bricks.end());
            delete brick;
            std::cout << "Brique supprimee" << std::endl;
            std::cout << "Il reste : " << bricks.size() << std::endl;
        }
    }
}

void GameManager::render() {
    window.clear();
    window.draw(oCanon.getShape());
    for (Brick* brick : bricks) {
        window.draw(brick->getShape());
    }
    window.draw(oBall.getShape());
    window.display();
}