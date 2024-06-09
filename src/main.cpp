#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <random>
#include "Particle.h"
#include "Renderer.h"


std::vector<Particle> test() {
    std::vector<Particle> particles;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> vel_dist(-0.5, 0.5);
    std::uniform_real_distribution<> vel_dist_abs(0.5, 0.5);
    std::uniform_real_distribution<> life_dist(9.0, 15.0);
    std::uniform_real_distribution<> clr_dist(0.0, 0.5);
    std::uniform_real_distribution<> clr_dist2(0.8, 1.0);

    for (int i = 0; i < 1000; ++i) {
        float x_vel = vel_dist(gen)*3;
        float y_vel = vel_dist_abs(gen);
        float z_vel = vel_dist(gen);
        float lifetime = life_dist(gen)*10;
        float g_val = clr_dist(gen);
        float r_val = clr_dist2(gen);
        particles.emplace_back(glm::vec3(0.0f, -1.0f, -20.0f), glm::vec3(x_vel, y_vel*9, z_vel), glm::vec3(0.0f, -1.0f, 0.0f), lifetime, 0.1f, Color(r_val, g_val), Color(r_val*2, g_val*2, 0.0f, 0.3f));
    }

    return particles;
}

int main(void) {
    Renderer renderer(800, 600);

    std::vector<Particle> particles = test();

   // Main loop
    while (!renderer.closeWindow()) {

        for (Particle& p : particles) {
            p.applyGravity(0.01f);
            p.update(0.01f);
        }
        renderer.renderParticles(particles);
        glfwPollEvents();
    }

    return 0;
}
