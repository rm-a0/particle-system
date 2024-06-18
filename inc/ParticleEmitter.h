#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include "Particle.h"
#include "ParticleManager.h"
#include <vector>

class ParticleEmitter {
public:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    float lifeSpan;
    float emissionRate;
    float lastEmission;
    Particle prototypeParticle;
    ParticleManager* manager;

    /* ParticleEmitter constructor
     * ---------------------------
     * Parameters:
     * const glm::vec3& pos, vel, acc
     * float lifespan, emissionRate
     * const Color& color
     * const Particle& prototypeP
     * ParticleManager& manager;
    */
    ParticleEmitter(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float emissionRate, const Particle& prototypeP, ParticleManager* manager);

    /* Particle emitter
     * ----------------
     * Parameters:
     * int count
    */
    void emit(int count);

    /* Update particles and emitter
     * ----------------------------
     * Parameters:
     * float deltaTime
    */
    void update(float deltaTime);
};


#endif // PARTICLE_EMITTER_H 
