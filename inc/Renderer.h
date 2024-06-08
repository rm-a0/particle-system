#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Particle.h"

class Renderer {
public:
    int screenWidth, screenHeight;
    glm::mat4 projectionMatrix, viewMatrix;
    GLFWwindow* window;

    /* Renderer constructor
     * --------------------
     * Parameters:
     * int screenWidth, screenHeight
    */
    Renderer(int screenWidth, int screenHeight);

    /* Renderer destructor
     * -------------------
     * Parameters:
     * None
    */
    ~Renderer();

    /* OpenGl initializer
     * -------------------
     * Parameters:
     * None
    */
    void initOpenGL();

    /* Particle renderer
     * -----------------
     * Parameters:
     * const Particle& particle
    */
    void renderParticle(const Particle& particle);
};

#endif // RENDERER_H
