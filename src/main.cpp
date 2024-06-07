#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.h"
#include "Renderer.h"

int main(void) {
    Particle particle(Vector3(50.0, 20.0), Vector3(), Vector3(), 500.0, 20.0, Color(100.0, 100.0, 100.0));
    Renderer renderer(800, 600);

    // Main loop
    while (!glfwWindowShouldClose(renderer.window)) {

        particle.update(0.1f);
        renderer.renderParticle(particle);
        glfwPollEvents();
    }

    return 0;
}


