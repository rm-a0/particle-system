#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.h"

void initialize() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

int main(void) {
    Vector3 pos(100.0, 100.0);
    Vector3 vel(10.0);
    Vector3 acc(0.0, 1.0);
    float lifespan = 5.0;

    Particle particle(pos, vel, acc, lifespan, Color(0.0, 1.1, 2.2));

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "3D Particle System", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    initialize();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}


