#pragma once

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
		return x - y;
	};

private:
	point x;
	point y;
};