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
    float initialLifeSpan;
    float size;
    Color color;
    Color initialColor;
    Color finalColor;

    /* Particle constructor
     * --------------------
     * Parameters:
     * const glm::vec3& pos, vel, acc
     * float lifespan
     * Color initClr, finalClr
    */
    Particle(const glm::vec3& pos, const glm::vec3& vel, const glm::vec3& acc, float lifeSpan, float size, const Color& initClr, const Color& finalClr);

    /* Particle update
     * ---------------
     * Parameters:
     * float deltaTime
     * Updates attributes based on delta time
    */
    void update(float deltaTime);

    /* Gravity aplication
     * ------------------
     * Parameters:
     * float deltaTime
     * Updates y.velocity based on delta time
    */
    void applyGravity(float deltaTime);

    /* Random Pattern
     * --------------
     * Parameters:
     * float deltaTime
     * Updates position and velocity randomly based on delta time
    */
    void applyRandomPattern(float deltaTime);
};

#endif // PARTICLE_H
