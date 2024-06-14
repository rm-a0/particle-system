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
        for (auto p = particles.begin(); p != particles.end();) {
                p->update(deltaTime);
                if (p->lifeSpan <= 0) {
                        p = particles.erase(p);
                }
                else {
                        ++p;
                }
        }

       for (auto e = emitters.begin(); e != emitters.end();) {
                e->update(deltaTime);
                if (e->lifeSpan <= 0) {
                        // e = emitters.erase(e);
                }
                        ++e;
        }
}

void ParticleManager::applyCircularPattern(float deltaTime, float radius, float angularSpeed) {
        for (auto& p : particles) {
                p.applyCircularPattern(deltaTime, radius, angularSpeed);
        }
}
