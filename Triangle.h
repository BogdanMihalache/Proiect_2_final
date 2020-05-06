#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Vect2D.h"

/*
 * Structura care defineste un triunghi in functie de 3 puncte.
 */
struct Triangle {
    Vect2D p[3];

    Triangle();
    Triangle(Vect2D p1, Vect2D p2, Vect2D p3);
};

#endif // Triangle_H_
