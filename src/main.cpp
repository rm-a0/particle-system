#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.h"

void init3D() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

GLFWwindow* initWindow() {
    if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return NULL;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Particle System", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return NULL;
    }

    init3D();

    return window;
}

int main(void) {
    GLFWwindow* window;

    Particle particle(Vector3(), Vector3(), Vector3(), 5.0, Color());

    if ((window = initWindow()) == NULL) {
        return 1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}


