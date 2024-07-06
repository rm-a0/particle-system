#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Particle.h"

class Renderer {
private:
    int screenWidth, screenHeight;
    glm::mat4 projectionMatrix, viewMatrix;
    GLFWwindow* window;
    GLuint vao, vbo;

public:
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

    /* VAO setup
     * ---------
     * Parameters:
     * None
    */
    void initVAO();

    /* Particle renderer
     * -----------------
     * Parameters:
     * const std::vector<Particle>& particles
    */
    void renderParticles(const std::vector<Particle>& particles);

    /* Square renderer
     * -----------------
     * Parameters:
     * const Particle& p
    */
    void renderSquare(const Particle& p, glm::mat4 modelMatrix);

    /* Close glfw window
     * -----------------
     * Parameters:
     * None
    */
    int closeWindow();
};

#endif // RENDERER_H
