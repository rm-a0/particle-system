#include "Particle.h"

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float lifeSpan)
        : position(pos), velocity(vel), acceleration(acc), lifeSpan(lifeSpan) {}

void Particle::update(float deltaTime) {
        velocity = velocity + acceleration * deltaTime;
        position = position + velocity * deltaTime;
        lifeSpan -= deltaTime;
}
