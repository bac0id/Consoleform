#pragma once
#ifndef __POINT_H
#define __POINT_H
class Point
{
public:
	Point();
	Point(int x, int y);
	int X;
	int Y;
	static Point Zero;
	static Point Up;
	static Point Down;
	static Point Left;
	static Point Right;
	Point& operator+(const Point& a);
	Point& operator-();
	Point& operator-(const Point& a);
	Point& operator*(int n);
	bool operator==(const Point& a);
	bool operator!=(const Point& a);
};
#endif // !__POINT_H
