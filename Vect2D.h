#ifndef VECT2D_H_
#define VECT2D_H_

#include <iostream>

struct Line;

/*
 * Structura care reprezinta un vector in plan, analog cu un punct.
 */
struct Vect2D {
	/*
	 * Coordonate
	 */
    double x;
    double y;

    Vect2D();
    Vect2D(double x, double y);

	/*
	 * Operatii de baza pe vectori
	 */
	double length() const;
	double distance(const Vect2D &v) const;
	double dot(const Vect2D &other) const;
	Vect2D normalized() const;

	/*
	 * Operatori matematici cu vectori / scalari
	 */
    Vect2D operator + (const Vect2D &other) const;
    Vect2D& operator += (const Vect2D &other);

    Vect2D operator - (const Vect2D &other) const;
    Vect2D& operator -= (const Vect2D &other);

	Vect2D operator * (double scalar) const;
	Vect2D& operator *= (double scalar);
};

std::ostream& operator << (std::ostream &os, const Vect2D &v);
std::istream& operator >> (std::istream &is, Vect2D &v);

#endif // VECT2D_H_

