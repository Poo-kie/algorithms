//
// Created by pookie on 11/11/18.
//

#ifndef PKEALGORITHMS_PKE_PLANAR_OPEARTIONS_H
#define PKEALGORITHMS_PKE_PLANAR_OPEARTIONS_H

#include <math.h>

#define D_TOLERANCE 0.000001

#define CROSS_PRODUCT(c1, c2, c3) ((c2.x - c1.x) * (c3.y - c1.y) - (c2.y - c1.y) * (c3.x - c1.x))
#define CROSS_PRODUCT_DIRECTION(cp) (cp < 0.0 ? RIGHT : cp > 0.0 ? LEFT : STRAIGHT)

// vector declarations and operations follow

#define VECTOR_X(vector) (vector.b.x - vector.a.x)
#define VECTOR_Y(vector) (vector.b.y - vector.a.y)

#define VECTOR_MAGNITUDE(vector) (sqrt(pow(VECTOR_X(vector), 2) + pow(VECTOR_Y(vector), 2)))
#define DOT_PRODUCT(vector1, vector2) (VECTOR_X(vector1) * VECTOR_X(vector2) + VECTOR_Y(vector1) * VECTOR_Y(vector2))

#define D_EQUAL(d1, d2) (fabs(d1 - d2) < D_TOLERANCE ? 1 : 0)

#endif //PKEALGORITHMS_PKE_PLANAR_OPEARTIONS_H
