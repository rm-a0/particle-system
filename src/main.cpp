#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.h"
#include "Renderer.h"

int main(void) {
    Particle particle(Vector3(), Vector3(1.0, 1.0, 3.0), Vector3(), 500.0, 20.0, Color(0.5, 0.2, 0.9));
    Renderer renderer(800, 600);

    // Main loop
    while (!glfwWindowShouldClose(renderer.window)) {

        particle.update(0.002f);
        renderer.renderParticle(particle);
        glfwPollEvents();
    }

    return 0;
}
