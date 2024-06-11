#pragma once

#include "line.h"
#include <vector>

class triangle{
public:
	triangle(std::vector<point*> pointsVector)
	{

		points = pointsVector;

		line lineA = line(*pointsVector[0], *pointsVector[1]);
		line lineB = line(*pointsVector[0], *pointsVector[2]);
		line lineC = line(*pointsVector[1], *pointsVector[2]);

		lines.push_back(lineA);
		lines.push_back(lineB);
		lines.push_back(lineC);

	};

	triangle() {
		point emptypoint = point();
		line emptyline = line();

		points.push_back(&emptypoint);
		points.push_back(&emptypoint);
		points.push_back(&emptypoint);

		lines.push_back(emptyline);
		lines.push_back(emptyline);
		lines.push_back(emptyline);
	};

	~triangle() {};

	bool isTriangle();
	bool isRightTriangle();
	void printTriangle();

private:
	std::vector<point*> points;
	std::vector<line> lines;

};