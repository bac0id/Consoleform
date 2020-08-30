#include "Point.h"
Point Point::Zero(0, 0);
Point Point::Up(-1, 0);
Point Point::Down(1, 0);
Point Point::Left(0, -1);
Point Point::Right(0, 1);

Point::Point() {
	this->X = this->Y = 0;
}

Point::Point(int x, int y) {
	this->X = x;
	this->Y = y;
}

Point& Point::operator+(const Point& a) {
	Point p(this->X + a.X, this->Y + a.Y);
	return p;
}

Point& Point::operator-() {
	Point p(-this->X, -this->Y);
	return p;
}

Point& Point::operator-(const Point& a) {
	Point p(this->X - a.X, this->Y - a.Y);
	return p;
}

Point& Point::operator*(int n) {
	Point p(this->X * n, this->Y * n);
	return p;
}

bool Point::operator==(const Point& a) {
	return this->X == a.X && this->Y == a.Y;
}

bool Point::operator!=(const Point& a) {
	return (this->X != a.X) || (this->Y != a.Y);
}

//Point& Point::operator+(const Point& a, const  Point& b)
//{
//	Point p(a.X + b.X, a.Y + b.Y);
//	return p;
//}
//
//Point& Point::operator-(const Point& a)
//{
//	Point p(-a.X, -a.Y);
//	return p;
//}
//
//Point& Point::operator-(const Point& a, const  Point& b)
//{
//	Point p(a.X - b.X, a.Y - b.Y);
//	return p;
//}
//
//Point& Point::operator*(const Point& a, int n)
//{
//	Point p(a.X * n, a.Y * n);
//	return p;
//}
//
//Point& Point::operator*(int n, const  Point& a)
//{
//	Point p(a.X * n, a.Y * n);
//	return p;
//}
//
//bool Point::operator==(const Point& a, const Point& b)
//{
//	return a.X == b.X && a.Y == b.Y;
//}
//
//bool Point::operator!=(const Point& a, const  Point& b)
//{
//	return (a.X != b.X) || (a.Y != b.Y);
//}
