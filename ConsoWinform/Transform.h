#pragma once
#ifndef __TRANSFORM_H
#define __TRANSFORM_H
#include <new>
#include "Point.h"
class Transform
{
public:
	Transform();
	Transform(Point& size, Point& loc);
	Point Size;
	Point Loc;
};
#endif // !__TRANSFORM_H