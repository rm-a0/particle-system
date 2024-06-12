#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <random>
#include <chrono>
#include <iostream>
#include "Particle.h"
#include "ParticleEmitter.h"
#include "ParticleManager.h"
#include "Renderer.h"

ParticleManager test() {
    ParticleManager manager;
        Particle p1 (glm::vec3(0.0), glm::vec3(1, 1, 1), glm::vec3(), 10.0, 1, Color(0.0, 0.5), Color(1.0, 0.5));
        ParticleEmitter e1 (glm::vec3(), glm::vec3(), glm::vec3(), 9, 10, Color(), p1, manager);
        manager.addParticleEmitter(e1);
    return manager;
}

int main(void) {
    Renderer renderer(800, 600);
    ParticleManager manager = test();

    auto lastFrameTime = std::chrono::high_resolution_clock::now();
   // Main loop
    while (!renderer.closeWindow()) {
        auto currentFrameTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentFrameTime - lastFrameTime).count();
        lastFrameTime = currentFrameTime;

        manager.applyCircularPattern(deltaTime, 200, 100);
        manager.update(deltaTime);
        renderer.renderParticles(manager.particles);
        glfwPollEvents();
    }

    return 0;
}
