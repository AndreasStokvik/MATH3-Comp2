#include <vector>
#include <string>
#include <glad/glad.h>

class GenGraph {
public:
    std::vector<GLfloat> mGraphVertices;
    std::string name;

    void readPointsFromFile(const std::string& filename);
};
