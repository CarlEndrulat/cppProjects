#pragma once

#include "triangle.h"
#include <iostream>
#include <mutex>

class square {
public:
	square() {
		point emptyPoint = point();

		for (int i = 0; i < 4; i++) {
			points.push_back(&emptyPoint);
		}
	};

	square(std::vector<point*>& vec)
	{
		points = vec;

		validSquare = (this->isSquare()) ? true : false;
	};

	~square() {};

	bool isSquare();

	bool getValidSquare() {
		return validSquare;
	};

	void printSquare();

private:
	std::vector<point*> points;

	bool validSquare;
};

struct Key
{
	std::string first;
	std::string second;
	std::string third;
	std::string fourth;

	bool operator==(const Key& other) const
	{
		return (first == other.first
			&& second == other.second
			&& third == other.third
			&& fourth == other.fourth);
	}
};

template <>
struct std::hash<Key>
{
	std::size_t operator()(const Key& k) const
	{
		using std::size_t;
		using std::hash;
		using std::string;

		return ((hash<string>()(k.first)
			^ (hash<string>()(k.second) << 1)) >> 1)
			^ (hash<string>()(k.third) << 1)
			^ (hash<string>()(k.fourth));
	}
};