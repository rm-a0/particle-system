#ifndef RENDERER_H
#define RENDERER_H

#include <GLFW/glfw3.h>
#include "Color.h"

class Renderer {
public:
    int screenWidth;
    int screenHeight;
    GLFWwindow* window;

    /* Renderer constructor
     * --------------------
     * Parameters:
     * int screenWidth, screenHeight
    */
    Renderer(int screenWidth, int screenHeight);

    /* Renderer destructor
     * -------------------
     * Parameters:
     * None
    */
    ~Renderer();

    void initOpenGL();
};

#endif // RENDERER_H
