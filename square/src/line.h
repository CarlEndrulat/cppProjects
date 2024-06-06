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

	line(const line& l) {
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
		//cout << "arbitrary line length = " << x - y << "\n";
		return x - y;
	};

private:
	point x;
	point y;
};