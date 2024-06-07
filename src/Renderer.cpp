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

        // Enable OpenGL functions
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

void Renderer::renderParticle(const Particle& p) {
        // Clear window
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render particle
        glPointSize(p.size);
        glBegin(GL_POINTS);
        glColor4f(p.color.r, p.color.g, p.color.b, p.color.a);
        glVertex3f(p.position.x, p.position.y, p.position.z);
        glEnd();

        glfwSwapBuffers(window);
}
