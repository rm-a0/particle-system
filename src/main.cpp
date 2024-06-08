#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <random>
#include "Particle.h"
#include "Renderer.h"

int main(void) {
    Renderer renderer(800, 600);

    std::vector<Particle> particles;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> vel_dist(0.4, 1.8);
    std::uniform_real_distribution<> vel_dist2(-0.8, 0.8);
    std::uniform_real_distribution<> life_dist(2.0, 5.0);
    std::uniform_real_distribution<> pos_dist(-1.0, 1.0);
    std::uniform_real_distribution<> clr_dist(0.0, 0.5);
    std::uniform_real_distribution<> clr_dist2(0.8, 1.0);

    for (int i = 0; i < 1000; ++i) {
        float y_vel = vel_dist(gen);
        float x_vel = vel_dist2(gen);
        float z_vel = -vel_dist(gen);
        float lifetime = life_dist(gen);
        float x_pos = pos_dist(gen);
        float g_val = clr_dist(gen);
        float r_val = clr_dist2(gen);
        particles.emplace_back(glm::vec3(x_pos, -2.0f, 0.0f), glm::vec3(x_vel, y_vel, z_vel), glm::vec3(0.0f), lifetime, 0.1f, Color(r_val, g_val));
    }
    // Main loop
    while (!glfwWindowShouldClose(renderer.window)) {

        for (Particle& p : particles) {
            p.update(0.01f);
        }
        renderer.renderParticles(particles);
        glfwPollEvents();
    }

    return 0;
}
