//
// Created by pookie on 11/11/18.
//

#ifndef PKEALGORITHMS_PKE_PLANAR_OBJECTS_H
#define PKEALGORITHMS_PKE_PLANAR_OBJECTS_H

typedef struct {
    double x;
    double y;
} coordinate_t;

typedef enum { LEFT, RIGHT, STRAIGHT } direction_t;

typedef struct {
    coordinate_t a;
    coordinate_t b;
} vector_t;

#endif //PKEALGORITHMS_PKE_PLANAR_OBJECTS_H
