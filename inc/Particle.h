#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector3.h"

class Particle {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    float lifeSpan;

    /* Particle constructor
     * --------------------
     * Parameters:
     * const Vector3& position, velocity acceleration
     * float lifespan
    */
 
    Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float lifespan);

    /* Particle update
     * ---------------
     * Parameters:
     * float deltaTime
     * Updates attributes based on delta time
    */
    void update(float deltaTime);
};

#endif // PARTICLE_H
