#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    float x;
} Point;

Point* new_Point() {
    Point* this = malloc(sizeof(Point));
    return this;
}

int main() {
    Point p1 = new_Point(0.000000, 0.000000);
}

float distance(Point a, Point b) {
    float dx = (0.x - 0.x);
}

