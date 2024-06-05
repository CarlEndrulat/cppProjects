//calculate whether item passed in main is a square or not

#include "square.h"

void main() {

	// TODO create large scale tester

	// TODO use std::move in constructors

	// TODO implement concurrency

	// TODO redo triangle to use vectors


	point a = point(0, 0);
	point b = point(0, 5);
	point c = point(5, 0);
	point d = point(5, 5);
	std::vector<point*> points = { &a, &b, &c, &d };

	square sq = square(points);

	cout << sq.isSquare() << "\n";

	cout << "end of main\n";
}