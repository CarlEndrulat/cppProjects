#include "square.h"

bool square::isSquare() {
	triangle tri0 = triangle(std::vector<point*>{points[0], points[1], points[2]});
	if (!tri0.isRightTriangle()) {
		return false;
	}

	triangle tri1 = triangle(std::vector<point*>{points[0], points[2], points[3]});
	if (!tri1.isRightTriangle()) {
		return false;
	}

	triangle tri2 = triangle(std::vector<point*>{points[0], points[1], points[3]});
	if (!tri2.isRightTriangle()) {
		return false;
	}

	return true;
}

void square::printSquare() {
	cout << "square\n";
	cout << points[0]->getx() << " " << points[0]->gety() << "\n";
	cout << points[1]->getx() << " " << points[1]->gety() << "\n";
	cout << points[2]->getx() << " " << points[2]->gety() << "\n";
	cout << points[3]->getx() << " " << points[3]->gety() << "\n";
}

void main() {

	// TODO create large scale tester

	// TODO use std::move in constructors

	// TODO implement concurrency


	point a = point(0, 0);
	point b = point(0, 5);
	point c = point(5, 0);
	point d = point(5, 5);
	std::vector<point*> points = { &a, &b, &c, &d };

	square sq = square(points);

	cout << sq.isSquare() << "\n";

	cout << "end of main\n";
}