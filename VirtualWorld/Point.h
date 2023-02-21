#pragma once
#include <iostream>

class Point {
private:
	int x;
	int y;
public:
	Point();
	Point(int x, int y);

	int GetX();
	int GetY();

	void SetX(int x);
	void SetY(int y);

	void DrawPoint();

	bool operator==(const Point& other);
	bool operator!=(const Point& other);
};
