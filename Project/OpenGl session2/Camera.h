#ifndef CAMERA_CLASS_H
#define GLM_ENABLE_EXPERIMENTAL
#define CAMERA_CLASS_H
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include "ShaderClass.h"






class Camera
{
public:
    glm::vec3 position;
    glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);

    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    bool firstClick;

    int width;
    int height;

    float speed = 0.001f;
    float sensitivity = 50.f;

    Camera(int width, int height, glm::vec3 position);  // Constructor

    void matrix(float FOVdeg, float nearPlane, float farPlane, ShaderClass& shader, const char* uniform);
    void inputs(GLFWwindow* window);
};
#endif