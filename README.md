# Overview
3D Particle system written in C++ using OpenGL and GLFW libraries.

# Description
To create particles, use the `Particle` class.
```cpp
Particle(position, velocity, acceleration, lifeSpan, size, initialColor, finalColor);
```
For creating emitters, use the `ParticleEmitter` class. \
Before creating an emitter, ensure that the example particle emitted by the emitter is defined, as well as the `ParticleManager`, which is necessary for storing and updating both emitters and particles.
```cpp
ParticleEmitter(position, velocity, acceleration, lifeSpan, emissionRate, color, prototypeParticle, manager);
```
After creating particles and emitters you can add them to `ParticleManager` class.
```cpp
manager.addParticle(particle);
manager.addParticleEmitter(emitter);
```
For rendering use `Renderer` class.
```cpp
Renderer(screenWidth, screenHeight);
```
To display particles on screen use
```cpp
renderer.renderParticles(manager.particles);
```
# How to Install and Run
Download or clone this repository
```
git clone https://github.com/rm-a0/particle-system
```
Install dependencies
```
sudo apt-get update
sudo apt-get install -y libgl1-mesa-dev libglu1-mesa-dev libglfw3-dev libglew-dev libglm-dev
```
Compile and run using
```
make run
```
# Updates and Features
- [x] Created window
- [x] Tested and rendered particle
- [x] Tested particle updating
- [x] Added camera and depth
- [x] Tested and optimalized for multiple particles
- [x] Added and tested color interpolation
- [x] Added particle emitter
- [x] Optimized rendering using VAOs
- [ ] Added patterns for particles
- [ ] Added particle emitter

# Bugs and Issues
- 2 errors from valgrind (issues with imported libraries)
- Max 10k paricles on low end grpahics (tested with Intel Tiger Lake-LP GT2)
