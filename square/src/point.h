#pragma once

#include <cmath>

class point {
public:
	point(int a, int b) {
		x = a;
		y = b;
	};

	point() {
		x = 0;
		y = 0;
	};

	point(point& p) {
		x = p.x; 
		y = p.y;
	};

	~point() {};

	double operator-(point rhs) {
		double l1 = abs(x - rhs.x);
		double l2 = abs(y - rhs.y);

		return sqrt(l1 * l1 + l2 * l2);
	};
	
	bool operator==(point rhs) {
		return (x == rhs.x && y == rhs.y) ? true : false;
	};

	point& operator = (const point& rhs) {
		x = rhs.x;
		y = rhs.y;
		return *this;
	};

private:
	double x;
	double y;
};