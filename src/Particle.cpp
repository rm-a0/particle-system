#include "Particle.h"

Particle::Particle(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float size, const Color& initClr, const Color& finalClr)
        : position(pos), velocity(vel), acceleration(acc), lifeSpan(lifeSpan), size(size), initialColor(initClr), finalColor(finalClr) {
                color = initialColor;
                initialLifeSpan = lifeSpan;
}

void Particle::update(float deltaTime) {
        velocity += acceleration * deltaTime;
        position +=  velocity * deltaTime;
        lifeSpan -= deltaTime;

        float t = 1.0f - (lifeSpan / initialLifeSpan);
        color = Color::interpolate(initialColor, finalColor, t);
}

void Particle::applyGravity(float deltaTime) {
        const float gravity = -1.0f;
        velocity.y += gravity * deltaTime;
}
