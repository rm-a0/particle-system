#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.h"
#include "Renderer.h"

int main(void) {
    Particle particle(Vector3(50.0, 20.0), Vector3(), Vector3(), 5.0, 2.0, Color());
    Renderer renderer(800, 600);

    // Main loop
    while (!glfwWindowShouldClose(renderer.window)) {

        glfwPollEvents();
    }

    return 0;
}


