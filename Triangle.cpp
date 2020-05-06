#include "Triangle.h"

/*
 * Constructor default, initializeaza un triunghi cu 3 puncte nule.
 */
Triangle::Triangle()
{
    Triangle(Vect2D(), Vect2D(), Vect2D());
}

/*
 * Constructor care initializeaza un triunghi in functie de 3 puncte date.
 */
Triangle::Triangle(Vect2D p1, Vect2D p2, Vect2D p3)
{
    this->p[0] = p1;
    this->p[1] = p2;
    this->p[2] = p3;
}

