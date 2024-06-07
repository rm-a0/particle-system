#include "Particle.h"

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float lifeSpan, float r, float g, float b)
        : position(pos), velocity(vel), acceleration(acc), lifeSpan(lifeSpan), r(r), g(g), b(b) {}

void Particle::update(float deltaTime) {
        velocity = velocity + acceleration * deltaTime;
        position = position + velocity * deltaTime;
        lifeSpan -= deltaTime;
}
