#include <vector>
#include <string>
#include <glad/glad.h>

struct Point {
    GLfloat x;
    GLfloat y;
};

class GenDots
{
public:
	std::vector<GLfloat> mDotsVertices;

	void GenDotCords(const std::vector<double>& Points);
};

