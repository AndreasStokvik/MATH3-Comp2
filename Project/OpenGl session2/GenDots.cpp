#include "GenDots.h"
#include <iostream>

void GenDots::GenDotCords(const std::vector<double>& Points)
{
    for (size_t i = 0; i < Points.size(); i += 2) {
        GLfloat x = Points[i];
        GLfloat y = Points[i + 1];
        GLfloat z = 0.0f;
        GLfloat r = 1.0f;
        GLfloat g = 1.0f;
        GLfloat b = 1.0f;

        mDotsVertices.push_back(x);
        mDotsVertices.push_back(y);
        mDotsVertices.push_back(z);
        mDotsVertices.push_back(r);
        mDotsVertices.push_back(g);
        mDotsVertices.push_back(b);

        //std::cout << "Read vertex: (" << x << ", " << y << ", " << z << "), color: (" << r << ", " << g << ", " << b << ")" << std::endl;
    }
}