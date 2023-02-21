#include "Point.h"
#include <iostream>
using namespace std;

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int Point::GetX() {
	return this->x;
}

int Point::GetY() {
	return this->y;
}

void Point::SetX(int x) {
	this->x = x;
}

void Point::SetY(int y) {
	this->y = y;
}

void Point::DrawPoint() {
	cout << "(" << this->x << "," << this->y << ")";
}

bool Point::operator==(const Point& other) {
	if (this->x == other.x && this->y == other.y) return true;
	else return false;
}

bool Point::operator!=(const Point& other) {
	if (this->x != other.x || this->y != other.y) return true;
	else return false;
}

