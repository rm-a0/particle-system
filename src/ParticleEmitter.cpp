#include "ParticleEmitter.h"
#include <iostream>

ParticleEmitter::ParticleEmitter(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float emissionRate, const Color& color, const Particle& prototypeP, ParticleManager& manager)
        : position(pos), velocity(vel), acceleration(acc), lifeSpan(lifeSpan), emissionRate(emissionRate), color(color), prototypeParticle(prototypeP), manager(manager) {
        lastEmission = 0.0f;
}

void ParticleEmitter::update(float deltaTime) {
        lastEmission += deltaTime;
        int particlesToEmit = static_cast<int>(emissionRate * lastEmission);
        if (particlesToEmit > 0) {
                emit(particlesToEmit);
                lastEmission -= particlesToEmit / emissionRate;
        }
}
void ParticleEmitter::emit(int count) {
        for (int i = 0; i < count; ++i) {
                Particle p = prototypeParticle;
                p.position = position;
                manager.addParticle(p);
        }
}
