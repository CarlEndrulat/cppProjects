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

	square(std::vector<point*> vec)
	{
		points = std::move(vec);
	};

	~square() {};

	bool isSquare();

	void printSquare();

private:
	std::vector<point*> points;
};