#pragma once

#include "triangle.h"
#include <iostream>

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

	bool isSquare();

private:
	std::vector<point*> points;
};