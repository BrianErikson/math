//
// Created by brian on 12/13/16.
//

#include "graphing.h"

#define MATH_POINT_OPEN 1


Graph1D math_graph1D(Operator1D operator, double val) {
    Graph1D graph = {0x0};
    switch(operator) {
        case LESS_THAN:
            graph.direction = -1;
            graph.point.open = 1;
            break;
        case LESS_THAN_EQUAL_TO:
            graph.direction = -1;
            graph.point.open = 0;
            break;
        case EQUAL_TO:
            graph.direction = 0;
            graph.point.open = 0;
            break;
        case GREATER_THAN:
            graph.direction = 1;
            graph.point.open = 1;
            break;
        case GREATER_THAN_EQUAL_TO:
            graph.direction = 1;
            graph.point.open = 0;
            break;
    }
    graph.point.position = val;
    return graph;
}