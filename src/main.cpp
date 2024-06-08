#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.h"
#include "Renderer.h"

int main(void) {
    Renderer renderer(800, 600);

    std::vector<Particle> particles;

    particles.push_back(Particle(glm::vec3(3.0f, 3.0f, 0.0f), glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(0.0f, 0.0f, 0.0f), 500.0, 0.2, Color(0.5, 0.2, 0.9)));
    particles.push_back(Particle(glm::vec3(-3.0f, -3.0f, 0.0f), glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(0.0f, 0.0f, 0.0f), 500.0, 0.2, Color(0.5, 0.2, 0.9)));

    // Main loop
    while (!glfwWindowShouldClose(renderer.window)) {

        for (Particle& p : particles) {
            p.update(0.01f);
        }
        renderer.renderParticles(particles);
        glfwPollEvents();
    }

    return 0;
}
