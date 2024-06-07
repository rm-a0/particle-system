#include "ParticleEmitter.h"


ParticleEmitter::ParticleEmitter(const Vector3& pos, const Vector3& vel, const Vector3& acc, float lifeSpan, float emissionRate, const Color& color)
        : position(pos), velocity(vel), acceleration(acc), lifeSpan(lifeSpan), emissionRate(emissionRate), color(color) {}
