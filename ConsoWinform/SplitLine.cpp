#include "SplitLine.h"
SplitLine::SplitLine(bool isHorizon, int offset, int length)
{
	new (this)SplitLine(isHorizon, offset, nullptr, length);
}

SplitLine::SplitLine(bool isHorizon, int offset, Component* parent)
{
	//Rect r;
	//if (isHorizon) {
	//	r.sizeX = 0;
	//	r.sizeY = parent->Transform.sizeY << 1;
	//	r.locX = offset;
	//	r.locY = 0;
	//}
	//else {
	//	r.sizeX = parent->Transform.sizeX;
	//	r.sizeY = 0;
	//	r.locX = 0;
	//	r.locY = offset;
	//}
	//this->Transform = r;
	//this->Parent = parent;


	new (this)SplitLine(isHorizon, offset, parent,
		isHorizon ? parent->Transform.sizeY << 1 : parent->Transform.sizeX);
}

SplitLine::SplitLine(bool isHorizon, int offset, Component* parent, int length)
{
	Rect r;
	if (isHorizon) {
		r.sizeX = 0;
		r.sizeY = length;
		r.locX = offset;
		r.locY = 0;
	}
	else {
		r.sizeX = length;
		r.sizeY = 0;
		r.locX = 0;
		r.locY = offset;
	}
	this->Transform = r;
	this->Parent = parent;
}

int SplitLine::GetLength()
{
	return this->Transform.sizeX == 0 ?
		this->Transform.sizeY : this->Transform.sizeX;
}

bool SplitLine::IsHorizon()
{
	return this->Transform.sizeX == 0 ? true : false;
}

void SplitLine::Draw()
{
	Display::DrawSplitLine(this);
}
