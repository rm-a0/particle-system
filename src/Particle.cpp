#include "Particle.h"

Particle::Particle(const Vector3& pos, const Vector3& vel, const Vector3& acc, float lifespan)
        : position(pos), velocity(vel), acceleration(acc), lifespan(lifespan) {}
