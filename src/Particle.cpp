#include "Particle.h"

Particle::Particle(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float size, const Color& color)
        : position(pos), velocity(vel), acceleration(acc), lifeSpan(lifeSpan), size(size), color(color) {}

void Particle::update(float deltaTime) {
        velocity += acceleration * deltaTime;
        position += velocity * deltaTime;
        lifeSpan -= deltaTime;
}
