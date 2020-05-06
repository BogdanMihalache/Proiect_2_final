#include "Vect2D.h"
#include "Line.h"

#include <math.h>
#include <iostream>

/*
 * Constructor default, initializeaza un punct in origine.
 */
Vect2D::Vect2D()
{
    Vect2D(0, 0);
}

/*
 * Constructor care initializeaza un punct pe baza unor coordonate date
 *
 * x, y -> coordonate in plan
 */
Vect2D::Vect2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

/*
 * Lungimea unui vector.
 */
double Vect2D::length() const
{
	return sqrt(this->x * this->x + this->y * this->y);
}

/*
 * Distanta dintre 2 puncte.
 *
 * v -> punctul fata de care se masoara distanta
 */
double Vect2D::distance(const Vect2D &v) const
{
	return (v - *this).length();
}

/*
 * Produs scalar intre 2 vectori.
 *
 * other -> al doilea argument al produsului
 */
double Vect2D::dot(const Vect2D &other) const
{
	return this->x * other.x + this->y * other.y;
}

/*
 * Metoda care intoarce vectorul normalizat (lungime 1).
 */
Vect2D Vect2D::normalized() const
{
	double length = this->length();
	return Vect2D(this->x / length, this->y / length);
}

/*
 * Adunare vectoriala.
 *
 * other -> al doilea vector din adunare
 */
Vect2D Vect2D::operator + (const Vect2D &other) const
{
    return Vect2D(this->x + other.x, this->y + other.y);
}

/*
 * Varianta in-place a adunarii vectoriale.
 */
Vect2D& Vect2D::operator += (const Vect2D &other)
{
    this->x += other.x;
    this->y += other.y;

    return *this;
}

/*
 * Scadere vectoriala.
 *
 * other -> scazatorul
 */
Vect2D Vect2D::operator - (const Vect2D &other) const
{
    return Vect2D(this->x - other.x, this->y - other.y);
}

/*
 * Varianta in-place a scaderii vectoriale.
 */
Vect2D& Vect2D::operator -= (const Vect2D &other)
{
    this->x -= other.x;
    this->y -= other.y;

    return *this;
}

/*
 * Inmultire scalara.
 *
 * scalar -> scalarul cu care se face inmultirea
 */
Vect2D Vect2D::operator * (double scalar) const
{
    return Vect2D(this->x * scalar, this->y * scalar);
}

/*
 * Varianta in-place a inmultirii scalare
 */
Vect2D& Vect2D::operator *= (double scalar)
{
    this->x *= scalar;
    this->y *= scalar;

    return *this;
}

/*
 * Afisare prin intermediul unui stream de output.
 *
 * os -> stream-ul de output
 * v -> vectorul afisat
 */
std::ostream& operator << (std::ostream &os, const Vect2D &v)
{
	os << "(" << v.x << "," << v.y << ")";
	return os;
}

/*
 * Citire prin intermediul unui stream de input.
 *
 * is -> stream-ul de input
 * v -> vectorul citit
 */
std::istream& operator >> (std::istream &is, Vect2D &v)
{
	is >> v.x >> v.y;
	return is;
}
