#pragma once
#ifndef __COLUMN_HEADER_H
#define __COLUMN_HEADER_H
#include <string>
#include "TextAlignment.h"
using namespace std;
class ColumnHeader
{
public:
	ColumnHeader();
	ColumnHeader(string text);
	ColumnHeader(string text, TextAlignment align);
private:
	string TextStr;
	TextAlignment Align;
};
#endif // !__COLUMN_HEADER_H
