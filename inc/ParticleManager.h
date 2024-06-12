#ifndef PARTICLE_MANAGER_H
#define PARTICLE_MANAGER_H

class ParticleEmitter;

#include "Particle.h"
#include <vector>

class ParticleManager {
public:
    std::vector<Particle> particles;
    std::vector<ParticleEmitter> emitters;

    /* ParticleManager constructor
     * --------------------------
     * Parameters:
     * None
    */
    ParticleManager();

    /* ParticleManager destructor
     * --------------------------
     * Parameters:
     * None
    */
    ~ParticleManager();

    /* Add Particle
     * ------------
     * Parameters:
     * const Particle& particle
    */
    void addParticle(const Particle& particle);

    /* Add ParticleEmitter
     * -------------------
     * Parameters:
     * const ParticleEmitter& emitter
    */
    void addParticleEmitter(const ParticleEmitter& emitter);

    /* Update and manage
     * -----------------
     * Parameters:
     * float deltaTime
    */
    void update(float deltaTime);

     /* Circular pattern
     * -----------------
     * Parameters:
     * float deltaTime, radius, angularSpeed
    */
    void applyCircularPattern(float deltaTime, float radius, float angularSpeed);
};

#endif // PARTICLE_MANAGER_H
