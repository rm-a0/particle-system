#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particle.h"

int main(void) {
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Particle System Test");
    Vector3 pos(100.0, 100.0);
    Vector3 vel(10.0);
    Vector3 acc(0.0, 1.0);
    float lifespan = 5.0;

    Particle particle(pos, vel, acc, lifespan);

    std::cout << particle.position.x << std::endl;

    return 0;
}
