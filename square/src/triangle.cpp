#include "triangle.h"

bool triangle::isTriangle() {
	if (*points[0] != *points[1] && *points[0] != *points[2] && *points[1] != *points[2]) {
		//cout << "a triangle!\n";
		return true;
	}
	//cout << "not a triangle!\n";
	return false;
};

bool triangle::isRightTriangle() {
	//cout << "test print isRight\n";

	if (isTriangle()) {
		double ll0 = lines[0].lineLength();
		double ll1 = lines[1].lineLength();
		double ll2 = lines[2].lineLength();
		//cout << "ll0=" << ll0 << " ll1=" << ll1 << " ll2=" << ll2 << "\n";

		if (ll0 == ll1) {
			return (ll2 == sqrt((ll1 * ll1) + (ll0 * ll0))) ? true : false;
		}
		else if (ll0 == ll2) {
			return (ll1 == sqrt((ll2 * ll2) + (ll0 * ll0))) ? true : false;
		}
		else if (ll1 == ll2) {
			return (ll0 == sqrt((ll1 * ll1) + (ll2 * ll2))) ? true : false;
		}
	}

	return false;
};

void triangle::printTriangle() {
	cout << "triangle\n";
	cout << points[0]->getx() << " " << points[0]->gety() << "\n";
	cout << points[1]->getx() << " " << points[1]->gety() << "\n";
	cout << points[2]->getx() << " " << points[2]->gety() << "\n";
}