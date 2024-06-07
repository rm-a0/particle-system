#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include "Particle.h"
#include "Vector3.h"
#include <vector>

class ParticleEmitter {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    float lifeSpan;
    float emissionRate;
    Color color;
    std::vector<Particle> particles;

    /* ParticleEmitter constructor
     * ---------------------------
     * Parameters:
     * const Vector3& position, velocity acceleration
     * float lifespan, emissionRate
     * Color color
    */
    ParticleEmitter(const Vector3& pos, const Vector3& vel, const Vector3& acc, float lifeSpan, float emissionRate, const Color& color);
};


#endif // PARTICLE_EMITTER_H 
