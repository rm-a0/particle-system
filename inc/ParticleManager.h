#ifndef PARTICLE_MANAGER_H
#define PARTICLE_MANAGER_H

#include "Particle.h"
#include "ParticleEmitter.h"
#include <vector>

class ParticleManager {
private:
    std::vector<Particle> particles;
    std::vector<ParticleEmitter> emitters;

public:
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
};

#endif // PARTICLE_MANAGER_H
