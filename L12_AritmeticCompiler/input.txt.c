#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    float x;
    float y;
} Point;

Point* new_Point(float x0, float y0) {
    Point* this = malloc(sizeof(Point));
    Point_init(this, x0, y0);
    return this;
}

void Point_init(Point* this, float x0, float y0) {
    this->x = x0;
    this->y = y0;
}

void Point_move(Point* this, float dx, float dy) {
    this->x = (this->x + dx);
    this->y = (this->y + dy);
}

void Point_print(Point* this) {
    printf("Point at (%f, %f)\n", this->x, this->y);
}

int main() {
    Point* p1 = new_Point(0.000000, 0.000000);
    Point* p2 = new_Point(3.000000, 4.000000);
    float d = distance(p1, p2);
    printf("Distance: %f\n", d);
    if ((d > 5.000000)) {
    printf(""Far apart"\n");
    } else {
    printf(""Close enough"\n");
    }
    int steps = 0;
    while ((distance(p1, p2) > 1.000000)) {
    move(0.500000, 0.500000);
    steps = (steps + 1);
    }
    printf("Reached in %f steps\n", steps);
    return 0;
}

float distance(Point a, Point b) {
    float dx = (a.x - b.x);
    float dy = (a.y - b.y);
    return sqrt(((dx * dx) + (dy * dy)));
}

