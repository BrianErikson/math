//
// Created by brian on A2/A2/A6.
//

#include "geometry.h"

double math_perimeterSquare(double side) {
    return 4 * side;
}

double math_perimeterRectangle(double sideA, double sideB) {
    return 2 * sideA + 2 * sideB;
}

double math_perimeterTriangle(double sideA, double sideB, double sideC) {
    return sideA + sideB + sideC;
}

double math_perimeterCircle(double radius) {
    return (2 * MATH_PI) * radius;
}