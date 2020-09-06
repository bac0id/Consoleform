#pragma once
#ifndef __CONTROL_H
#define __CONTROL_H
#include <typeinfo>
#include "Rect.h"

class Control
{
public:
	//位置信息
	Rect Transform;
	//父组件位置
	Control* Parent;
	//显示组件
	virtual void Draw() = 0;
private:
	static const char* ControlsOrderTable[];
};
#endif // !__CONTROL_H
