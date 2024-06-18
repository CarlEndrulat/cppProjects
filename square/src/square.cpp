#include "square.h"
#include <chrono>
#include <thread>
#include <functional>
#include <unordered_map>
#include <mutex>

using std::chrono::steady_clock;
using std::chrono::duration;

using namespace std::chrono_literals;

void testSquare(std::vector<point*> points, bool success, double loops, double& successCount);

//globals
std::unordered_map<Key, square> squareCache;
std::mutex squareCacheMutex;


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
			squareCacheMutex.lock();
			squareCache.emplace(key, sq);
			squareCacheMutex.unlock();
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

	// TODO use smart pointers (especially for lines)

	double testLimit = 100000;
	std::vector<double> successCount = {0, 0, 0, 0};
	double totalSuccess = 0;

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

	point a4 = point(2, 1);
	point b4 = point(-1, 2);
	point c4 = point(1, -2);
	point d4 = point(-2, -1);
	bool success4 = true;

	std::vector<point*> points1 = { &a1, &b1, &c1, &d1 };
	std::vector<point*> points2 = { &a2, &b2, &c2, &d2 };
	std::vector<point*> points3 = { &a3, &b3, &c3, &d3 };
	std::vector<point*> points4 = { &a4, &b4, &c4, &d4 };

	auto t1 = steady_clock::now();

	//std::thread thread1(testSquare, points1, success1, testLimit, std::ref(successCount1));
	//std::thread thread2(testSquare, points2, success2, testLimit, std::ref(successCount2));
	//std::thread thread3(testSquare, points3, success3, testLimit, std::ref(successCount3));
	//std::thread thread4(testSquare, points4, success4, testLimit, std::ref(successCount4));

	std::thread thread1(testSquare, points1, success1, testLimit, std::ref(successCount[0]));
	std::thread thread2(testSquare, points2, success2, testLimit, std::ref(successCount[1]));
	std::thread thread3(testSquare, points3, success3, testLimit, std::ref(successCount[2]));
	std::thread thread4(testSquare, points4, success4, testLimit, std::ref(successCount[3]));
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();

	duration<double> dur1 = steady_clock::now() - t1;
	for (auto success : successCount) {
		cout << success << "\n";
		totalSuccess += success;
	}

	cout << "Successful test percentage = " << (totalSuccess)/testLimit/successCount.size()*100 << " percent\n";
	cout << "output took " << dur1 << " seconds\n";

	cout << "end of main\n";
}