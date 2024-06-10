#include "ParticleManager.h"

ParticleManager::ParticleManager() {}

ParticleManager::~ParticleManager() {}

void ParticleManager::addParticle(const Particle& particle) {
        particles.push_back(particle);
}

void ParticleManager::addParticleEmitter(const ParticleEmitter& emitter) {
        emitters.push_back(emitter);
}

void ParticleManager::update(float deltaTime) {
        for (auto& p : particles) {
                p.update(deltaTime);
        }
        for (auto& e : emitters) {
                e.update(deltaTime);
        }
}
