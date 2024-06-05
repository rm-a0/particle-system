#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector3.h"

class Particle {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    float lifespan;

    Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float lifespan);
};

#endif // PARTICLE_H
