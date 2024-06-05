#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particle.h"

int main(void) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particle System Test");
    Vector3 pos(100.0, 100.0);
    Vector3 vel(10.0);
    Vector3 acc(0.0, 1.0);
    float lifespan = 5.0;

    Particle particle(pos, vel, acc, lifespan);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        particle.update(deltaTime);

        window.clear();
        window.display();
    }

    return 0;
}
