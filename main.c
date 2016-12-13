#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "geometry.h"
#include "graphing.h"

#define stringIs(str, target) \
    (int)(strcmp(str, target) == 0)

#define C_PERIMETER "perimeter"
#define C_GRAPH     "graph"


void printHelp(char *operation) {
    if (operation == NULL) {
        puts("Usage: math <operation> [OPTIONS]");
        puts("For help on an operation, type \"math <operation> --help\"");
        puts("Operations:");
        puts("\tGeometry:");
        puts("\t\tperimeter [--circle] <length> [length] [length]");
        puts("\tGraphing:");
        puts("\t\tmath graph <variableName> '<comparisonSymbol>' <value>");
        return;
    }
    else if (stringIs(C_PERIMETER, operation)) {
        puts("Usage: math perimeter [--circle] <length> [length] [length]");
        puts("\tCircle: math perimeter --circle <radius>");
        puts("\tSquare: math perimeter <sideLength>");
        puts("\tRectangle: 20math perimeter <sideALength> <sideBLength>");
        puts("\tTriangle: math perimeter <sideALength> <sideBLength> <sideCLength>");
    }
    else if (stringIs(C_GRAPH, operation)) {
        puts("Usage: math graph <variableName> '<comparisonSymbol>' <value>");
    }
    else {
        puts("No help associated with this command");
    }
}

void parsePerimeter(int optionLen, char **options) {
    if (optionLen < 1) {
        printHelp(C_PERIMETER);
        return;
    }

    if (stringIs("--circle", options[0])) {
        if (optionLen != 2) {
            printHelp(C_PERIMETER);
            return;
        }
        double result = math_perimeterCircle(strtod(options[1], NULL));
        printf("%lf\n", result);
        return;
    }

    int valLen = optionLen;
    double result;
    switch(valLen) {
        case 0:
            printHelp(C_PERIMETER);
            break;
        case 1:
            result = math_perimeterSquare(strtod(options[0], NULL));
            printf("%lf\n", result);
            break;
        case 2:
            result = math_perimeterRectangle(strtod(options[0], NULL), strtod(options[1], NULL));
            printf("%lf\n", result);
            break;
        case 3:
            result = math_perimeterTriangle(strtod(options[0], NULL),
                                            strtod(options[1], NULL),
                                            strtod(options[2], NULL));
            printf("%lf\n", result);
            break;
        default:
            printHelp(C_PERIMETER);
    }
}

Operator1D parseOperator(char *op) {
    errno = 0x0;
    if (stringIs("<", op))
        return LESS_THAN;
    else if (stringIs("<=", op))
        return LESS_THAN_EQUAL_TO;
    else if (stringIs("=", op))
        return EQUAL_TO;
    else if (stringIs(">=", op))
        return GREATER_THAN_EQUAL_TO;
    else if (stringIs(">", op))
        return GREATER_THAN;
    errno = 0x1;
    return LESS_THAN;
}

void draw1dGraph(Graph1D graph) {
    double *pos = &graph.point.position;
    char ltchar, gtchar;
    if (graph.direction < 0) {
        ltchar = '=';
        gtchar = '-';
    }
    else {
        ltchar = '-';
        gtchar = '=';
    }

    printf("<");
    for (double curPos = *pos - 4; curPos < *pos + 5; curPos++) {
        if (curPos <= graph.point.position)
            putchar(ltchar);
        else
            putchar(gtchar);

        if (curPos == graph.point.position) {
            if (graph.point.open == 1)
                putchar('O');
            else
                putchar('@');
        }
        else
            putchar('|');

    }
    putchar(gtchar);
    puts(">");

    // TODO: Render numbers under graph for context
}

void parseGraph(int optionLen, char **options) {
    if (optionLen < 3) {
        printHelp(C_GRAPH);
    }
    else if (optionLen == 3) {
        Operator1D op = parseOperator(options[1]);
        if (errno == 0x1) printHelp(C_GRAPH);

        double val = strtod(options[2], NULL);
        draw1dGraph(math_graph1D(op, val));
    }
    else {
        printHelp(C_GRAPH);
    }
    return;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printHelp(NULL);
        return 0;
    }
    else if (argc == 3 && stringIs("--help", argv[2])) {
        printHelp(argv[1]);
        return 0;
    }
    char *operation = argv[1];
    int optionLen = argc - 2;
    char **options = &argv[2];

    if (stringIs(C_PERIMETER, operation)) {
        parsePerimeter(optionLen, options);
    }
    else if (stringIs(C_GRAPH, operation)) {
        parseGraph(optionLen, options);
    }

    return 0;
}