#pragma once

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

	bool isTriangle();
	bool isRightTriangle();

private:
	std::vector<point*> points;
	std::vector<line*> lines;

};