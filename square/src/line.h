#pragma once

#include <iostream>
#include <cmath>
#include "point.h"
using namespace std;



class line {
public:

	line() {
		x = point();
		y = point();
	}

	line(point a, point b) {
		x = a;
		y = b;
	};

	line(line& l) {
		x = l.x;
		y = l.y;
	};

	line& operator = (const line& rhs) {
		x = rhs.x;
		y = rhs.y;
		return *this;
	};

	~line() {};

	double lineLength() {
		return this->x - this->y;
	};

	bool sharePoint(line a) {
		return (x == a.x || y == a.y || y == a.x || x == a.y) ? true : false;
	}

private:
	point x;
	point y;
};