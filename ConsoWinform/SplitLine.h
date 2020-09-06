#pragma once
#ifndef __SPLITLINE_H
#define __SPLITLINE_H
#include <new>
#include <iostream>
#include "Display.h";
#include "Control.h"
class SplitLine : public Control
{
public:
	SplitLine(bool isHorizon, int offset, int length);
	SplitLine(bool isHorizon, int offset, Control* parent);
	SplitLine(bool isHorizon, int offset, Control* parent, int length);
	int GetLength();
	bool IsHorizon();
	void Draw();
};
#endif // !__SPLITLINE_H
