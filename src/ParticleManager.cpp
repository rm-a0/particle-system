#include "ParticleManager.h"

ParticleManager::ParticleManager() {}

void ParticleManager::addParticle(const Particle& particle) {
        particles.push_back(particle);
}

void ParticleManager::addParticleEmitter(const ParticleEmitter& emitter) {
        emitters.push_back(emitter);
}
