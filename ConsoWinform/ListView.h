#pragma once
#ifndef __LISTVIEW_H
#define __LISTVIEW_H
#include "Display.h"
#include "Control.h"
using namespace std;

class ListView : public Control
{
public:
	ListView();
	ListView(Rect& transform);

	void DrawColumns();
	void DrawPage(int pageIndex);
	void Select(int index);
	int GetColumnCount();
	int GetItemCount();
	int GetCurrentItemIndex();
	int GetLastItemIndex();
	int GetPageCount();
	int GetCurrentPageIndex();
	int GetItemCountPerPage();
private:
	//列数量
	int ColumnCount;
	//行数量
	int ItemCount;
	//当前选中行索引
	int CurrentItemIndex;
	//上一次选中行索引
	int LastItemIndex;

	//页面数量
	int PageCount;
	//当前页面索引
	int CurrentPageIndex;
	
	//每页行数
	int ItemCountPerPage;

	int PageInterval(int index);
};
#endif // !__LISTVIEW_H
class 