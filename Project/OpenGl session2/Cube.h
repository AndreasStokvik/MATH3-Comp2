#include <vector>
#include <glm/glm.hpp>
#include <string>


struct Vertex {
    float x, y, z, r, g, b;
};

class Cube
{
public:
    std::vector<Vertex> mCubeVertecies;
    glm::mat4 matrix;
    std::string name;

    Cube(float scale) : a(scale)
    {
        Vertex v0{ -a, -a, a , 1.0f, 0.3f, 0.0f };
        Vertex v1{ a, -a, a , 1.0f, 0.2f, 0.1f };
        Vertex v2{ a, a, a , 1.0f, 0.0f, 0.0f };
        Vertex v3{ -a, a, a , 1.0f, 0.0f, 0.0f };
        Vertex v4{ -a, -a, -a , 0.0f, 0.8f, 5.0f };
        Vertex v5{ a, -a, -a , 0.0f, 0.8f, 5.0f };
        Vertex v6{ a, a, -a , 0.0f, 0.8f, 5.0f };
        Vertex v7{ -a, a, -a , 0.0f, 0.8f, 5.0f };


        // Front face

        mCubeVertecies.push_back(v0);
        mCubeVertecies.push_back(v1);
        mCubeVertecies.push_back(v3);
        mCubeVertecies.push_back(v3);
        mCubeVertecies.push_back(v1);
        mCubeVertecies.push_back(v2);

        // Back face
        mCubeVertecies.push_back(v4);
        mCubeVertecies.push_back(v5);
        mCubeVertecies.push_back(v7);
        mCubeVertecies.push_back(v7);
        mCubeVertecies.push_back(v5);
        mCubeVertecies.push_back(v6);

        // Right face
        mCubeVertecies.push_back(v1);
        mCubeVertecies.push_back(v5);
        mCubeVertecies.push_back(v2);
        mCubeVertecies.push_back(v2);
        mCubeVertecies.push_back(v5);
        mCubeVertecies.push_back(v6);

        // Left face
        mCubeVertecies.push_back(v4);
        mCubeVertecies.push_back(v0);
        mCubeVertecies.push_back(v7);
        mCubeVertecies.push_back(v7);
        mCubeVertecies.push_back(v0);
        mCubeVertecies.push_back(v3);

        // Top face
        mCubeVertecies.push_back(v3);
        mCubeVertecies.push_back(v2);
        mCubeVertecies.push_back(v7);
        mCubeVertecies.push_back(v7);
        mCubeVertecies.push_back(v2);
        mCubeVertecies.push_back(v6);

        // Bottom face
        mCubeVertecies.push_back(v4);
        mCubeVertecies.push_back(v5);
        mCubeVertecies.push_back(v0);
        mCubeVertecies.push_back(v0);
        mCubeVertecies.push_back(v5);
        mCubeVertecies.push_back(v1);
    }

private:
    float a{ 1.0f };
};