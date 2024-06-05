#pragma once

//

#include "line.h"
#include <vector>

class triangle{
public:
	triangle(point& a, point& b, point& c)
	{
		points.push_back(&a);
		points.push_back(&b);
		points.push_back(&c);

		line lineA = line(a, b);
		line lineB = line(a, c);
		line lineC = line(b, c);

		lines.push_back(&lineA);
		lines.push_back(&lineB);
		lines.push_back(&lineC);
	};

	triangle() {
		point emptypoint = point();
		line emptyline = line();

		points.push_back(&emptypoint);
		points.push_back(&emptypoint);
		points.push_back(&emptypoint);

		lines.push_back(&emptyline);
		lines.push_back(&emptyline);
		lines.push_back(&emptyline);
	};

	~triangle() {};

	bool isTriangle() {
		if (points[0] != points[1] && points[0] != points[2] && points[1] != points[2]) {
			return true;
		}

		return false;
	};

	bool isRightTriangle() {

		if (isTriangle()) {
			double ll0 = lines[0]->lineLength();
			double ll1 = lines[1]->lineLength();
			double ll2 = lines[2]->lineLength();

			if (ll0 == ll1) {
				return (ll2 == sqrt(ll1 * ll1 + ll0 * ll0)) ? true : false;
			}
			else if (ll0 == ll2) {
				return (ll1 == sqrt(ll2 * ll2 + ll0 * ll0)) ? true : false;
			}
			else if (ll1 == ll2) {
				return (ll0 == sqrt(ll1 * ll1 + ll2 * ll2)) ? true : false;
			}
		}

		return false;
	};

private:
	std::vector<point*> points;
	std::vector<line*> lines;

};