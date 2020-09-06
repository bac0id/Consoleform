#pragma once
#ifndef __LISTVIEW_H
#define __LISTVIEW_H
#include "Display.h"
#include "Control.h"
using namespace std;

class ListView : public Control
{
public:
	void DrawColumns();
	void DrawPage(int pageIndex);

}

#endif // !__LISTVIEW_H
