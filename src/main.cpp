#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particle.h"

int main(void) {
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Particle System Test");
    Vector3 pos(100.0f, 100.0f, 0.0f);
    Vector3 vel(10.0f, 0.0f, 0.0f);
    Vector3 acc(0.0f, 1.0f, 0.0f);
    float lifespan = 5.0f;

    Particle particle(pos, vel, acc, lifespan);

    std::cout << particle.position.x << std::endl;

    return 0;
}
