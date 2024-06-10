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
        initVAO();
}

Renderer::~Renderer() {
        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);
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

        float cameraDist = 50.0f;
        viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, cameraDist),
                                 glm::vec3(0.0f, 0.0f, 0.0f),
                                 glm::vec3(0.0f, 1.0f, 0.0f));
}

void Renderer::initVAO() {
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4 * 6, nullptr, GL_DYNAMIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
}

void Renderer::renderParticles(const std::vector<Particle>& particles) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (const Particle& p : particles) {
                glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), p.position);
                glm::mat4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;

                float halfSize = p.size / 2.0f;
                float verticies[] = {
                        -halfSize, -halfSize, 0.0f, p.color.r, p.color.g, p.color.b,
                        halfSize, -halfSize, 0.0f, p.color.r, p.color.g, p.color.b,
                        halfSize,  halfSize, 0.0f, p.color.r, p.color.g, p.color.b,
                        -halfSize,  halfSize, 0.0f, p.color.r, p.color.g, p.color.b
                };
                glBindBuffer(GL_ARRAY_BUFFER, vbo);
                glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verticies), verticies);

                // Use the fixed-function pipeline to load the MVP matrix and draw
                glMatrixMode(GL_PROJECTION);
                glLoadMatrixf(glm::value_ptr(projectionMatrix));
                glMatrixMode(GL_MODELVIEW);
                glLoadMatrixf(glm::value_ptr(viewMatrix * modelMatrix));

                glBegin(GL_QUADS);
                for (int i = 0; i < 4; ++i) {
                    glColor3f(verticies[6 * i + 3], verticies[6 * i + 4], verticies[6 * i + 5]);
                    glVertex3f(verticies[6 * i + 0], verticies[6 * i + 1], verticies[6 * i + 2]);
                }
                glEnd();
        }

    glfwSwapBuffers(window);
}

int Renderer::closeWindow() {
        return glfwWindowShouldClose(window);
}
