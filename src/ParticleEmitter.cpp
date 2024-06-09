#include "ParticleEmitter.h"


ParticleEmitter::ParticleEmitter(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float emissionRate, const Color& color, std::vector<Particle>& particles)
        : position(pos), velocity(vel), acceleration(acc), lifeSpan(lifeSpan), emissionRate(emissionRate), color(color), particles(particles) {
}
