#ifndef PRINTFUNCTION_H
#define PRINTFUNCTION_H

#include <vector>
#include <string>

class PrintFunction {
public:
    PrintFunction(const std::string& equation);

    void generateCoordinates(int n, const std::string& outputFile);

private:
    std::vector<double> coefficients;

    void parseEquation(const std::string& equation);

    double evaluateFunction(double x) const;
};

#endif // PRINTFUNCTION_H
