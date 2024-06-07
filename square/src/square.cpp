#include "square.h"
#include <chrono>

using std::chrono::steady_clock;
using std::chrono::duration;

using namespace std::chrono_literals;

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

	// TODO improve large scale tester

	// TODO use smart pointers (especially for lines)

	// TODO implement concurrency

	double testLimit = 100000;
	double testSuccess = 0;

	point a1 = point(0, 0);
	point b1 = point(0, 5);
	point c1 = point(5, 0);
	point d1 = point(5, 5);
	bool success1 = true;

	point a2 = point(-2, -2);
	point b2 = point(-2, 8);
	point c2 = point(8, -2);
	point d2 = point(8, 8);
	bool success2 = true;

	point a3 = point(1, 0);
	point b3 = point(0, 5);
	point c3 = point(5, 0);
	point d3 = point(5, 5);
	bool success3 = false;

	std::vector<point*> points1 = { &a1, &b1, &c1, &d1 };
	std::vector<point*> points2 = { &a2, &b2, &c2, &d2 };
	std::vector<point*> points3 = { &a3, &b3, &c3, &d3 };

	auto t1 = steady_clock::now();

	for (int i = 0; i < testLimit; i++) {
		square sq1 = square(points1);
		square sq2 = square(points2);
		square sq3 = square(points3);

		if ((sq1.getValidSquare() == success1) && (sq2.getValidSquare() == success2) && (sq3.getValidSquare() == success3)) {
			testSuccess++;
		}
	}

	duration<double> dur1 = steady_clock::now() - t1;

	cout << "Successful test percentage = " << testSuccess/testLimit*100 << " percent\n";
	cout << "output took " << dur1 << "seconds\n";

	cout << "end of main\n";
}