#ifndef ROBOT_H_
#define ROBOT_H_

#include "Vect2D.h"
#include "Triangle.h"

/*
 * Structura care defineste un robot circular.
 */
struct Robot {
	/*
	 * Proprietati ale robotului.
	 *
	 * position  -> pozitia intr-un spatiu 2D
	 * radius    -> raza robotului
	 * corner    -> indicele coltului din zona neacoperita in care se afla robotul
	 * first_lap -> indicator care specifica daca robotul poate acoperi
	 *              tot spatiul din urmatorul colt
	 */
	Vect2D position;
	double radius;
	int corner;
	bool first_lap;

	/*
	 * Robotul retine un triunghi care reprezinta
	 * suprafata pe care o mai are de parcurs.
	 */
	Triangle remaining_area;

	/*
	 * Camp actualizat in momentul in care robotul
	 * termina de parcurs camera.
	 */
	bool done;

	/*
	 * Functii de interactionare cu robotul.
	 */
	void init(const Triangle &room);
	void fill_room();
	void next_corner();
	void log_position();
};

#endif // ROBOT_H_

