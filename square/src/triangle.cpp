#include "triangle.h"

bool triangle::isTriangle() {
	if (points[0] != points[1] && points[0] != points[2] && points[1] != points[2]) {
		return true;
	}

	return false;
};

bool triangle::isRightTriangle() {

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