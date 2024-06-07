#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include "Color.h"

class Particle {
public:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    float lifeSpan;
    float size;
    Color color;

    /* Particle constructor
     * --------------------
     * Parameters:
     * const glm::vec3& position, velocity acceleration
     * float lifespan
     * Color color
    */
    Particle(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float size, const Color& color);

    /* Particle update
     * ---------------
     * Parameters:
     * float deltaTime
     * Updates attributes based on delta time
    */
    void update(float deltaTime);
};

#endif // PARTICLE_H
