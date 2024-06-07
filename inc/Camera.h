#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

class Camera {
public:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::mat4 viewMatrix;
    float yaw;
    float pitch;


};

#endif // CAMERA_H
