#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector3.h"
#include "Color.h"

class Particle {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    float lifeSpan;
    Color color;

    /* Particle constructor
     * --------------------
     * Parameters:
     * const Vector3& position, velocity acceleration
     * float lifespan
     * Color color
    */
    Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float lifespan, const Color& color);

    /* Particle update
     * ---------------
     * Parameters:
     * float deltaTime
     * Updates attributes based on delta time
    */
    void update(float deltaTime);
};

#endif // PARTICLE_H
