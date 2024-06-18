#include "ParticleEmitter.h"
#include <iostream>
#include <random>

ParticleEmitter::ParticleEmitter(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float emissionRate, const Particle& prototypeP, ParticleManager* manager)
        : position(pos), velocity(vel), acceleration(acc), lifeSpan(lifeSpan), emissionRate(emissionRate), prototypeParticle(prototypeP), manager(manager) {
        lastEmission = 0.0f;
}

void ParticleEmitter::update(float deltaTime) {
        velocity += acceleration * deltaTime;
        position +=  velocity * deltaTime;
        lifeSpan -= deltaTime;

        lastEmission += deltaTime;
        int particlesToEmit = static_cast<int>(emissionRate * lastEmission);
        if (particlesToEmit > 0) {
                emit(particlesToEmit);
                lastEmission -= particlesToEmit / emissionRate;
        }
}
void ParticleEmitter::emit(int count) {
        std::random_device rd; // Seed
        std::mt19937 gen(rd()); // Mersenne Twister generator
        std::uniform_real_distribution<> distribution(-prototypeParticle.size, prototypeParticle.size);
        for (int i = 0; i < count; ++i) {
                float randomPosition = 5*distribution(gen);
                Particle p = prototypeParticle;
                p.position = position+randomPosition;
                manager->addParticle(p);
        }
}
