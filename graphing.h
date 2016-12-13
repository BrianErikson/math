//
// Created by brian on 12/13/16.
//

#ifndef MATH_GRAPHING_H
#define MATH_GRAPHING_H

typedef struct Point1D_s {
    unsigned char open; // 0 if closed/filled, 1 if open
    double position;
} Point1D;

typedef enum Operator1D_s {
    LESS_THAN,
    LESS_THAN_EQUAL_TO,
    EQUAL_TO,
    GREATER_THAN_EQUAL_TO,
    GREATER_THAN
} Operator1D;

typedef struct Graph1D_s {
    Point1D point;
    char direction; // -1 if negative, 0 if point, 1 if positive
} Graph1D;

Graph1D math_graph1D(Operator1D operator, double val);

#endif //MATH_GRAPHING_H
