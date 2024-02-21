#include "PrintFunction.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

PrintFunction::PrintFunction(const std::string& equation) {
    parseEquation(equation);
}

void PrintFunction::generateCoordinates(int n, const std::string& outputFile) {
    std::ofstream file(outputFile);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << outputFile << std::endl;
        return;
    }

    double step = 2.0 / (n - 1);
    double x = -1.0;
    for (int i = 0; i < n; ++i) {
        double y = evaluateFunction(x);
        file << x << " " << y << std::endl;
        x += step;
    }

    file.close();
    std::cout << "Coordinates generated and saved to: " << outputFile << std::endl;
}

void PrintFunction::parseEquation(const std::string& equation) {
    std::istringstream iss(equation);
    std::string term;
    while (iss >> term) {
        if (term == "x" || term == "^" || term == "+")
            continue;
        coefficients.push_back(std::stod(term));
    }
    //std::cout << equation << std::endl;
}

double PrintFunction::evaluateFunction(double x) const {
    double result = 0.0;
    int degree = coefficients.size() - 1;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * std::pow(x, degree - i);
    }
    return result;
}
