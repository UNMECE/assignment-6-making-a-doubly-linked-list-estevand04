#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
public:
    float x;
    float y;
    int coord_id;
    Coordinate* next;
    Coordinate* previous;

    Coordinate(float x, float y, int id) : x(x), y(y), coord_id(id), next(nullptr), previous(nullptr) {}
};

#endif // COORDINATE_H
