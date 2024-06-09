#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float emissionRate, const Color& color, Particle prototypeP)
        : position(pos), velocity(vel), acceleration(acc), lifeSpan(lifeSpan), emissionRate(emissionRate), color(color), prototypeParticle(prototypeP) {
}

void ParticleEmitter::emit(float deltaTime) {
}
