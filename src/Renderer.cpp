#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
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

        projectionMatrix = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float) screenHeight, 0.1f, 1000.0f);

        viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f),
                                 glm::vec3(0.0f, 0.0f, 0.0f),
                                 glm::vec3(0.0f, 1.0f, 0.0f));
}

void Renderer::renderParticles(const std::vector<Particle>& particles) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (const Particle& p : particles) {
                glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), p.position);
                glm::mat4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;

                glMatrixMode(GL_PROJECTION);
                glLoadMatrixf(glm::value_ptr(mvpMatrix));

                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();

                glColor4f(p.color.r, p.color.g, p.color.b, p.color.a);

                // Draw quad (two triangles) for the particle
                glBegin(GL_TRIANGLES);
                float halfSize = p.size / 2.0f;
                glVertex3f(-halfSize, -halfSize, 0.0f);
                glVertex3f(halfSize, -halfSize, 0.0f);
                glVertex3f(halfSize, halfSize, 0.0f);

                glVertex3f(-halfSize, -halfSize, 0.0f);
                glVertex3f(halfSize, halfSize, 0.0f);
                glVertex3f(-halfSize, halfSize, 0.0f);
                glEnd();
        }

        glfwSwapBuffers(window);
}

int Renderer::closeWindow() {
        return glfwWindowShouldClose(window);
}
