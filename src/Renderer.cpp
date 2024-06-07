#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"

Renderer::Renderer(int screenWidth, int screenHeight)
        : screenWidth(screenWidth), screenHeight(screenHeight) {
        // Init GLFW
        if (!glfwInit()) {
                std::cerr << "Failed to initialize GLFW" << std::endl;
        }

        // Create window
        window = glfwCreateWindow(screenWidth, screenHeight, "Partice System", NULL, NULL);
        if (!window) {
                std::cerr << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
        }
        glfwMakeContextCurrent(window);

        // Init OpenGL
        if (glewInit() != GLEW_OK) {
                std::cerr << "Failed to initialize OpenGL" << std::endl;
        }

        initOpenGL();
}

Renderer::~Renderer() {
        if (window) {
                glfwDestroyWindow(window);
                glfwTerminate();
        }
}

void Renderer::initOpenGL() {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
