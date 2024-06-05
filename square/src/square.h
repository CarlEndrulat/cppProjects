#pragma once

#include "triangle.h"

class square {
public:
	square() {
		point emptyPoint = point();

		for (int i = 0; i < 4; i++) {
			points.push_back(&emptyPoint);
		}
	}

	square(auto vec)
	{
		points = vec;
	};

	~square() {};

	bool isSquare() {
		triangle tri0 = triangle(*points[0], *points[1], *points[2]);
		if (!tri0.isRightTriangle()) {
			return false;
		}

		triangle tri1 = triangle(*points[0], *points[2], *points[3]);
		if (!tri1.isRightTriangle()) {
			return false;
		}

		triangle tri2 = triangle(*points[0], *points[1], *points[3]);
		if (!tri2.isRightTriangle()) {
			return false;
		}

		return true;
	}

private:
	std::vector<point*> points;
};