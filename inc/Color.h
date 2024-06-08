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

    /* Color addition
     * --------------
     * Parameters:
     * const Color& color
    */
    Color operator+(const Color& color) const;

    /* Color multiplication
     * --------------------
     * Parameters:
     * float scalar
    */
    Color operator*(float scalar) const;

    /* Interpolate color
     * -----------------
     * Parameters:
     * const Color& start, end
     * float t
    */
    static Color interpolate(const Color& start, const Color& end, float t);
};

#endif // COLOR_H
