#include <iostream>
#include "Robot.h"
#include "Triangle.h"
#include "Vect2D.h"

int main() {
	Robot robot;
	Triangle t1, t2;

	Vect2D p1, p2, p3, p4;

	std::cin >> p1;
	std::cin >> p2;
	std::cin >> p3;
	std::cin >> p4;
	std::cin >> robot.radius;

	t1 = Triangle(p1, p2, p3);
	t2 = Triangle(p3, p4, p1);

	robot.init(t1);
	robot.fill_room();

	robot.init(t2);
	robot.fill_room();

	return 0;
}

