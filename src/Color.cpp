#include "Color.h"

Color::Color(float r, float g, float b, float a)
        : r(r), g(g), b(b), a(a) {}

Color Color::operator+(const Color& color) const {
        return Color(r + color.r, g + color.g, b + color.b, a + color.a);
}

Color Color::operator*(float scalar) const {
        return Color(r * scalar, g * scalar, b * scalar, a * scalar);
}

Color Color::interpolate(const Color& start, const Color& end, float t) {
        return start * (1.0 - t) + end * t;
}
