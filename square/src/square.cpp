#include "square.h"
#include <chrono>
#include <thread>
#include <functional>
#include <unordered_map>

using std::chrono::steady_clock;
using std::chrono::duration;

using namespace std::chrono_literals;

void testSquare(std::vector<point*> points, bool success, double loops, double& successCount);

//globals
std::unordered_map<Key, square> squareCache;


bool square::isSquare() {
	triangle tri0 = triangle(std::vector<point*>{points[0], points[1], points[2]});
	if (!tri0.isRightTriangle()) {
		return false;
	}

	triangle tri1 = triangle(std::vector<point*>{points[0], points[2], points[3]});
	if (!tri1.isRightTriangle()) {
		return false;
	}

	triangle tri2 = triangle(std::vector<point*>{points[0], points[1], points[3]});
	if (!tri2.isRightTriangle()) {
		return false;
	}

	return true;
}

void square::printSquare() {
	cout << "square\n";
	cout << points[0]->getx() << " " << points[0]->gety() << "\n";
	cout << points[1]->getx() << " " << points[1]->gety() << "\n";
	cout << points[2]->getx() << " " << points[2]->gety() << "\n";
	cout << points[3]->getx() << " " << points[3]->gety() << "\n";
}

void testSquare(std::vector<point*> points, bool success, double loops, double& successCount) {
	cout << "test square started\n";
	Key key = {
		points[0]->pointString(),
		points[1]->pointString(),
		points[2]->pointString(),
		points[3]->pointString(),
	};
	for (int i = 0; i < loops; i++) {
		auto fret = squareCache.find(key);
		if (fret == squareCache.end()) {
			square sq = square(points);

			if ((sq.getValidSquare() == success)) {
				successCount++;
			}
			squareCache.emplace(key, sq); // create hashing - redefine hash map to try to use a custom string generator that uses the point vector
		}
		else {
			if ((squareCache[key].getValidSquare() == success)) {
				successCount++;
			}
		}
	}
	cout << "finished threaed!\n";
}


void main() {

	// TODO improve large scale tester

	// TODO use smart pointers (especially for lines)

	// TODO create some sort of caching - implement mutex

	double testLimit = 100000;
	double successCount1 = 0;
	double successCount2 = 0;
	double successCount3 = 0;

	point a1 = point(0, 0);
	point b1 = point(0, 5);
	point c1 = point(5, 0);
	point d1 = point(5, 5);
	bool success1 = true;

	point a2 = point(-2, -2);
	point b2 = point(-2, 8);
	point c2 = point(8, -2);
	point d2 = point(8, 8);
	bool success2 = true;

	point a3 = point(1, 0);
	point b3 = point(0, 5);
	point c3 = point(5, 0);
	point d3 = point(5, 5);
	bool success3 = false;

	std::vector<point*> points1 = { &a1, &b1, &c1, &d1 };
	std::vector<point*> points2 = { &a2, &b2, &c2, &d2 };
	std::vector<point*> points3 = { &a3, &b3, &c3, &d3 };

	auto t1 = steady_clock::now();

	std::thread thread1(testSquare, points1, success1, testLimit, std::ref(successCount1));
	//std::thread thread2(testSquare, points2, success2, testLimit, std::ref(successCount2));
	//std::thread thread3(testSquare, points3, success3, testLimit, std::ref(successCount3));

	thread1.join();
	//thread2.join();
	//thread3.join();

	duration<double> dur1 = steady_clock::now() - t1;
	cout << successCount1 << " " << successCount2 << " " << successCount3 << "\n";

	cout << "Successful test percentage = " << (successCount1 + successCount2 + successCount3)/testLimit/3*100 << " percent\n";
	cout << "output took " << dur1 << " seconds\n";

	cout << "end of main\n";
}