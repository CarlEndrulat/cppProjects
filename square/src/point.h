#pragma once

#include <cmath>

class point {
public:
	point(int a, int b) {
		x = a;
		y = b;
	};

	point() {
		this->x = 0;
		this->y = 0;
	};

	// TODO use std::move
	point(point& p) {
		x = p.x; 
		y = p.y;
	};

	~point() {};

	double getx() {
		return this->x;
	};

	double gety() {
		return this->y;
	};

	double operator-(point b) {
		double l1 = abs(this->x - b.getx());
		double l2 = abs(this->y - b.gety());

		return sqrt(l1 * l1 + l2 * l2);
	};
	
	bool operator==(point rhs) {
		return (x == rhs.getx() && y == rhs.gety()) ? true : false;
	};

	point& operator = (const point& rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
		return *this;
	};

private:
	double x;
	double y;
};