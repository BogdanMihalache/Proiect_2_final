#include "Robot.h"
#include "Line.h"
#include <iostream>


/*
 * Functie de initializare a robotului pe baza unei camere triunghiulare.
 * Robotul va fi pozitionat in interiorul camerei, cat mai aproape de primul
 * colt al triunghiului.
 */
void Robot::init(const Triangle &room)
{
	Line edge1 = Line(room.p[0], room.p[1]);
	Line edge2 = Line(room.p[0], room.p[2]);

	Line line1 = edge1.parallel(this->radius, room.p[2]);
	Line line2 = edge2.parallel(this->radius, room.p[1]);

	this->position = line1.intersection(line2);

	this->remaining_area = room;
	this->done = false;
	this->corner = 0;
	this->first_lap = true;
	std::cout << this->position << " "
		<< room.p[0] << " " << room.p[1] << " " << room.p[2] << std::endl;
}

void Robot::fill_room()
{
	while (not this->done) {
		this->next_corner();
	}
}

/*
 * Functie de parcurgerea a camerei.
 * In urma apelului, robotul se va deplasa spre urmatorul colt
 * al zonei neacoperite, in lungul unei laturi.
 * Daca robotul termina de parcurs camera, variabila done este setata
 * la valoarea true.
 */
void Robot::next_corner()
{
	int first = corner;
	int second = (corner + 1) % 3;
	int third = (corner + 2) % 3;

	corner = second;
	// daca robotul a ajuns inapoi la coltul initial, putem incepe
	// sa completam zonele libere din colturi
	if (corner == 0) {
		first_lap = false;
	}

	Line edge1 = Line(this->remaining_area.p[second], this->remaining_area.p[first]);
	Line edge2 = Line(this->remaining_area.p[second], this->remaining_area.p[third]);
	Line edge3 = Line(this->remaining_area.p[first], this->remaining_area.p[third]);

	Line line1 = edge1.parallel(this->radius, this->remaining_area.p[third]);
	Line line2 = edge2.parallel(this->radius, this->remaining_area.p[first]);

	Vect2D target = line1.intersection(line2);

	Line new_edge = edge1.parallel(2 * this->radius, this->remaining_area.p[third]);

	Vect2D new_p_first = new_edge.intersection(edge3);
	Vect2D new_p_second = new_edge.intersection(edge2);

	if (not first_lap) {
		Line line3 = edge2.parallel(-this->radius, this->remaining_area.p[first]);
		Vect2D secondary_target = line3.intersection(line1);
		this->position = secondary_target;

		this->log_position();
	}

	if (new_p_first.distance(this->remaining_area.p[first]) >
			this->remaining_area.p[third].distance(this->remaining_area.p[first])
			|| new_p_second.distance(this->remaining_area.p[second]) >
			this->remaining_area.p[third].distance(this->remaining_area.p[second])) {
		this->done = true;
		return;
	}

	this->remaining_area.p[first] = new_p_first;
	this->remaining_area.p[second] = new_p_second;
	this->position = target;

	this->log_position();
}

void Robot::log_position()
{
	std::cout << this->position << " ";
	for (int i = 0; i < 3; ++i) {
		std::cout << this->remaining_area.p[i] << " ";
	}
	std::cout << std::endl;
}
