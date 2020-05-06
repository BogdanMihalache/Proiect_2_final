#include "Line.h"
#include "Vect2D.h"

#include <iostream>

/*
 * Constructor default, initializeaza o linie orizontala care trece prin origine.
 */
Line::Line()
{
    Line(Vect2D(), Vect2D(1, 0));
}

/*
 * Constructor care initializeaza linia in functie de 2 puncte date.
 *
 * p1, p2 -> puncte in plan
 */
Line::Line(Vect2D p1, Vect2D p2)
{
    this->p1 = p1;
    this->p2 = p2;
}

/*
 * Metoda care returneaza o linie paralela, trasata pe partea specificata de un punct.
 *
 * distance -> distanta liniei paralele fata de linia originala
 * hint -> punctul care determina partea pe care e trasata paralela.
 */
Line Line::parallel(double distance, const Vect2D &hint)
{
	Vect2D vect = p2 - p1;
	Vect2D perpendicular = Vect2D(vect.y, -vect.x).normalized();

	if (not this->same_side(perpendicular + p1, hint)) {
		perpendicular *= -1;
	}

	perpendicular *= distance;

    return Line(this->p1 + perpendicular, this->p2 + perpendicular);
}

/*
 * Metoda care determina intersectia a 2 linii.
 *
 * line -> linia cu care se face intersectia
 */
Vect2D Line::intersection(const Line &line)
{
    double x1 = this->p1.x;
    double y1 = this->p1.y;
    double x2 = this->p2.x;
    double y2 = this->p2.y;

    double x3 = line.p1.x;
    double y3 = line.p1.y;
    double x4 = line.p2.x;
    double y4 = line.p2.y;

    double xi, yi;

    xi = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) /
        ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));

    yi = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) /
        ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));

    return Vect2D(xi, yi);
}

/*
 * Metoda care determina partea unei linii pe care se afla un punct.
 *
 * point -> punctul analizat
 *
 * Returneaza o valoare negativa daca punctul se afla pe o parte si
 * o valoare pozitiva daca se afla pe cealalta.
 */
double Line::side(const Vect2D &point) const
{
	double x1 = this->p1.x;
    double y1 = this->p1.y;

    double x2 = this->p2.x;
    double y2 = this->p2.y;

    double x = point.x;
    double y = point.y;

    return (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
}

/*
 * Metoda care determina daca 2 puncte sunt de aceeasi parte a unei linii.
 *
 * p1, p2 -> cele 2 puncte
 */
bool Line::same_side(const Vect2D &p1, const Vect2D &p2) const
{
	if (this->side(p1) * this->side(p2) > 0) {
        return true;
    }
    return false;
}
