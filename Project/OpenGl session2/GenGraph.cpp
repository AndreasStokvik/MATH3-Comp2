#include "GenGraph.h"
#include <fstream>
#include <sstream>
#include <iostream>

void GenGraph::readPointsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        GLfloat x, y, z = 0.0f, r = 1.0f, g = 1.0f, b = 1.0f;
        if (!(iss >> x >> y)) {
            std::cerr << "Error: Invalid line in file " << filename << std::endl;
            continue;
        }
        mGraphVertices.push_back(x);
        mGraphVertices.push_back(y);
        mGraphVertices.push_back(z);
        mGraphVertices.push_back(r);
        mGraphVertices.push_back(g);
        mGraphVertices.push_back(b); 
        
        
        std::cout << "Read vertex: (" << x << ", " << y << ", " << z << "), color: (" << r << ", " << g << ", " << b << ")" << std::endl;
    }

    file.close();
}
