#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
public:
    float x, y, z;

    /* Vector constructor
     * ------------------
     * Parameters:
     * float x, y, z
     * Initial values are 0.0f unless specified otherwise
    */
    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    /* Vector addition
     * ---------------
     * Parameters:
     * const Vector3& vect
     * Performs basic vector addition
    */
    Vector3 operator+(const Vector3& vect) const;

    /* Vector substraction
     * -------------------
     * Parameters:
     * const Vector3& vect
     * Performs basic vector substraction
    */
    Vector3 operator-(const Vector3& vect) const;

    /* Vector multiplication
     * ---------------------
     * Parameters:
     * float scalar
     * Multiplies vector by a scalar
    */
    Vector3 operator*(float scalar) const;

    /* Vector division
     * ---------------
     * Parameters:
     * float scalar
     * Divides vector by a scalar
    */
    Vector3 operator/(float scalar) const;

    /* Compound vector addition
     * ------------------------
     * Parameters:
     * const Vector3& vect
     * Performs compound addition of vectors
    */
    Vector3& operator+=(const Vector3& vect);

    /* Compound vector substraction
     * ----------------------------
     * Parameters:
     * const Vector3& vect
     * Performs compound substraction of vectors
    */
    Vector3& operator-=(const Vector3& vect);
};

#endif // VECTOR3_H
