#include "ParticleManager.h"
#include "ParticleEmitter.h"

ParticleManager::ParticleManager() {}

ParticleManager::~ParticleManager() {}

void ParticleManager::addParticle(const Particle& particle) {
        particles.push_back(particle);
}

void ParticleManager::addParticleEmitter(const ParticleEmitter& emitter) {
        emitters.push_back(emitter);
}

void ParticleManager::update(float deltaTime) {
        for (auto it = particles.begin(); it != particles.end();) {
                it->update(deltaTime);
                if (it->lifeSpan <= 0) {
                        it = particles.erase(it);
                }
                else {
                        ++it;
                }
        }

        for (auto& e : emitters) {
                e.update(deltaTime);
        }
}

void ParticleManager::applyCircularPattern(float deltaTime, float radius, float angularSpeed) {
        for (auto& p : particles) {
                p.applyCircularPattern(deltaTime, radius, angularSpeed);
        }
}
