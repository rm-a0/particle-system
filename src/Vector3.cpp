#include "Vector3.h"

Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3& vect) const {
    return Vector3(x + vect.x, y + vect.y, z + vect.z);
}

Vector3 Vector3::operator-(const Vector3& vect) const {
    return Vector3(x - vect.x, y - vect.y, z - vect.z);
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(float scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3& Vector3::operator+=(const Vector3& vect) {
    x += vect.x;
    y += vect.y;
    z += vect.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& vect) {
    x -= vect.x;
    y -= vect.y;
    z -= vect.z;
    return *this;
}
