#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include "Particle.h"
#include <vector>

class ParticleEmitter {
public:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    float lifeSpan;
    float emissionRate;
    float lastEmission;
    Color color;
    Particle prototypeParticle;
    std::vector<Particle> particles;

    /* ParticleEmitter constructor
     * ---------------------------
     * Parameters:
     * const glm::vec3& pos, vel, acc
     * float lifespan, emissionRate
     * const Color& color
     * const Particle& prototypeP
    */
    ParticleEmitter(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float emissionRate, const Color& color, const Particle& prototypeP);

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
