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
    Color color;
    std::vector<Particle> particles;

    /* ParticleEmitter constructor
     * ---------------------------
     * Parameters:
     * const glm::vec3& position, velocity acceleration
     * float lifespan, emissionRate
     * Color color
    */
    ParticleEmitter(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float emissionRate, const Color& color);
};


#endif // PARTICLE_EMITTER_H 
