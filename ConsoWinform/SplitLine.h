#pragma once
#ifndef __SPLITLINE_H
#define __SPLITLINE_H
#include <new>
#include <iostream>
#include "Display.h";
#include "Component.h"
class SplitLine : public Component
{
public:
	SplitLine(bool isHorizon, int offset, int length);
	SplitLine(bool isHorizon, int offset, Component* parent);
	SplitLine(bool isHorizon, int offset, Component* parent, int length);
	int GetLength();
	bool IsHorizon();
	void Draw();
};
#endif // !__SPLITLINE_H