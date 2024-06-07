#ifndef COLOR_H
#define COLOR_H

class Color {
public:
    float r, g, b, a;

    /* Color constructor
     * -----------------
     * Parameters:
     * float r, g, b, a
    */
    Color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);
};

#endif // COLOR_H
