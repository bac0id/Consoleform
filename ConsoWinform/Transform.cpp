#include "Transform.h"

Transform::Transform()
{
	Point size(0, 0);
	Point loc(0, 0);
	new (this)Transform(size, loc);
}

Transform::Transform(Point& size, Point& loc)
{
	this->Size = size;
	this->Loc = loc;
}
