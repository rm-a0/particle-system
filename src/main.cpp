#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <random>
#include <chrono>
#include <iostream>
#include "Particle.h"
#include "ParticleEmitter.h"
#include "ParticleManager.h"
#include "Renderer.h"

ParticleEmitter test2(ParticleManager& manager) {
    Particle p (glm::vec3(0.0), glm::vec3(10.0, 10.0, 50.0), glm::vec3(0.0), 100.0, 1.0f, Color(1.0, 0.5), Color(1.0, 0.5));
    ParticleEmitter emitter(glm::vec3(0.0), glm::vec3(0.0), glm::vec3(0.0), 9, 1, Color(1.0), p, manager);
    return emitter;
}

ParticleEmitter test3(ParticleManager& manager) {
    Particle p (glm::vec3(0.0), glm::vec3(-10.0, -10.0, -50.0), glm::vec3(0.0), 100.0, 1.0f, Color(1.0, 0.5), Color(1.0, 0.5));
    ParticleEmitter emitter(glm::vec3(0.0), glm::vec3(0.0), glm::vec3(0.0), 9, 1, Color(1.0), p, manager);
    return emitter;
}

int main(void) {
    Renderer renderer(800, 600);
    ParticleManager manager;

    ParticleEmitter e = test2(manager);
    ParticleEmitter e1 = test3(manager);
    manager.addParticleEmitter(e);
    manager.addParticleEmitter(e1);


    auto lastFrameTime = std::chrono::high_resolution_clock::now();
   // Main loop
    while (!renderer.closeWindow()) {
        auto currentFrameTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentFrameTime - lastFrameTime).count();
        lastFrameTime = currentFrameTime;

        manager.update(deltaTime);
        renderer.renderParticles(manager.particles);
        glfwPollEvents();
    }

    return 0;
}
