#include <iostream>
#include <string>
#include <Windows.h>

#include "Display.h"
#include "Control.h"
using namespace std;
/// <summary>
/// 设置光标坐标
/// </summary>
/// <param name="x">行</param>
/// <param name="y">列</param>
void Display::SetCursorPos(int x, int y) {
	//x和y互换一下，方便编程
	COORD coord = { y,x };
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
}
/*
得到光标坐标
参数：	无
返回：	表示光标坐标的COORD型。
*/
COORD Display::GetCursorPos() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	GetConsoleScreenBufferInfo(hout, &pBuffer);
	return pBuffer.dwCursorPosition;
}
/*
设置光标可见度
参数：	visible: 光标是否可见
返回：	无
*/
void Display::SetCursorVisibility(bool visible) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hout, &CursorInfo);
	CursorInfo.bVisible = visible;
	SetConsoleCursorInfo(hout, &CursorInfo);
}
/*
设置窗口尺寸
参数：	x: 行
		y: 列
返回：	无
*/
void Display::SetConsoleSize(int x, int y) {
	////x和y互换一下，方便编程
	//SMALL_RECT size = { y,x };
	//HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleWindowInfo(hout, true, &size);
	char szStrCmd[ 32 ];
	sprintf_s(szStrCmd, "mode con lines=%d cols=%d", x, y);
	system(szStrCmd);
}
/*
设置字体颜色
参数：	color: 颜色
返回：	无
*/
void Display::SetColor(int color) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//auto a = FOREGROUND_RED
	SetConsoleTextAttribute(hout, color);
}
void Display::ResetColor() {
	SetColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}
/*
清屏
参数：	无
返回：	无
*/
void Display::Clear() {
	system("cls");
}
/*
在原点绘制指定矩形
参数：	x: 高度
		y: 宽度
返回：	空
*/
void Display::DrawRect(int x, int y) {
	DrawRect(x, y, 0, 0);
}
/*
在指定坐标绘制指定矩形
参数：	x: 高度
		y: 宽度
		offsetX: 起始点X坐标
		offsetY: 起始点Y坐标
返回：	空
*/
void Display::DrawRect(int x, int y, int offsetX, int offsetY) {
	DrawRect(x, y, offsetX, offsetY, false);
}
/*
在指定坐标绘制指定矩形
参数：	x: 高度
		y: 宽度
		offsetX: 起始点X坐标
		offsetY: 起始点Y坐标
		fill: 是否填充内部
返回：	空
*/
void Display::DrawRect(int x, int y, int offsetX, int offsetY, bool fill) {
	int i;
	//1个大字符占2格
	y <<= 1, offsetY <<= 1;
	//上边
	SetCursorPos(offsetX, offsetY);
	cout << "╔";
	for (i = 0; i <= y; cout << "═", ++i);
	cout << "╗";
	//中间
	if (fill) {
		for (i = 1; i <= x; ++i) {
			SetCursorPos(offsetX + i, offsetY);
			cout << "║";
			for (int j = 0; j <= y; ++j) {
				cout << ' ';
			}
			cout << "║";
		}
	} else {
		for (i = 1; i <= x; ++i) {
			SetCursorPos(offsetX + i, offsetY);
			cout << "║";
			SetCursorPos(offsetX + i, offsetY + y + 2);
			cout << "║";
		}
	}
	//下边
	SetCursorPos(offsetX + x + 1, offsetY);
	cout << "╚";
	for (i = 0; i <= y; cout << "═", ++i);
	cout << "╝";
}
/*
绘制执行矩形
参数：	rect: 指定1个矩形
返回：	空
*/
void Display::DrawRect(Rect* rect) {
	DrawRect(rect->sizeX, rect->sizeY, rect->locX, rect->locY);
}
/*
绘制执行矩形
参数：	rect: 指定1个矩形
		fill: 是否填充内部
返回：	空
*/
void Display::DrawRect(Rect* rect, bool fill) {
	DrawRect(rect->sizeX, rect->sizeY, rect->locX, rect->locY, fill);
}
/*
在指定坐标打印字符串
参数：	x: 高度
		y: 宽度
		str: 字符串
返回：	无
*/
void Display::DrawString(int x, int y, char* str) {
	SetCursorPos(x, y);
	cout << str;
}
/*
在指定坐标打印字符串
参数：	x: 高度
		y: 宽度
		str: 字符串
返回：	无
*/
void Display::DrawString(int x, int y, string str) {
	SetCursorPos(x, y);
	cout << str;
}
/*
在指定矩形内的指定相对坐标打印字符串
参数：	rect*: 矩形
		x: 高度
		y: 宽度
		str: 字符串
返回：	无
*/
void Display::DrawString(Rect* rect, int x, int y, char* str) {
	DrawString(rect->locX + x, (rect->locY << 1) + y, str);
	//SetCursor(rect->startX + x, (rect->startY << 1) + y);
	//cout << str;
}
/*
在指定矩形内的指定相对坐标打印字符串
参数：	rect*: 矩形
		x: 高度
		y: 宽度
		str: 字符串
返回：	无
*/
void Display::DrawString(Rect* rect, int x, int y, string str) {
	DrawString(rect->locX + x, (rect->locY << 1) + y, str);
	//SetCursor(rect->startX + x, (rect->startY<<1) + y);
	//cout << str;
}
/*
打印文本
参数：	rect: 矩形
		label: 文本
返回：	无
*/
void Display::DrawLabel(Text* label) {
	//if (!label->Parent) {
	//	SetColor(label->GetColor());
	//	DrawString(label->Transform.locX, label->Transform.locY, label->GetStr());
	//	ResetColor();
	//	return;
	//}
	//DrawLabel(&label->Parent->Transform, label);

	int x = label->Transform.locX;
	int y = label->Transform.locY;
	if (label->Parent!=nullptr) {
		x += label->Parent->Transform.locX;
		y += label->Parent->Transform.locY << 1;
	}
	SetColor(label->GetColor());
	DrawString(x, y, label->GetStr());
	ResetColor();
}
/*
在指定矩形内的打印文本
参数：	rect: 矩形
		label: 文本
返回：	无
*/
void Display::DrawLabel(Rect* rect, Text* label) {
	SetColor(label->GetColor());
	DrawString(rect->locX + label->Transform.locX,
		(rect->locY << 1) + label->Transform.locY, label->GetStr());
	ResetColor();
}
///*
//绘制分割线
//参数：	rect: 矩形
//		isHerizon: 是否是水平线
//		start: 起点坐标
//		length: 长度
//返回：	无
//*/
//void Display::DrawSplitLine(Rect* rect, bool isHerizon, int start, int length)
//{
//	//水平线
//	if (isHerizon) {
//		DrawSplitLine(rect, true, start, 0, length);
//	}
//	else {
//		DrawSplitLine(rect, false, 0, start, length);
//	}
//}
///*
//绘制分割线
//参数：	isHerizon: 是否是水平线
//		startX: 起点X坐标
//		startY: 起点Y坐标
//		length: 长度
//返回：	无
//*/
//void Display::DrawSplitLine(bool isHerizon, int startX, int startY, int length)
//{
//	SetCursorPos(startX, startY);
//	int i;
//	//水平线
//	if (isHerizon) {
//		cout << "╠";
//		for (i = 0; i <= length; cout << "═", ++i);
//		cout << "╣";
//	}
//	//铅垂线
//	else {
//		cout << "╦";
//		for (i = 0; i <= length; ++i) {
//			SetCursorPos(startX++, startY);
//			cout << "║";
//		}
//		cout << "╩";
//	}
//}
///*
//绘制分割线
//参数：	rect: 矩形
//		isHerizon: 是否是水平线
//		startX: 起点X坐标
//		startY: 起点Y坐标
//		length: 长度
//返回：	无
//*/
//void Display::DrawSplitLine(Rect* rect, bool isHerizon, int startX, int startY, int length)
//{
//	SetCursorPos(rect->locX + startX, (rect->locY << 1) + startY);
//	int i;
//	//水平线
//	if (isHerizon) {
//		cout << "╠";
//		for (i = 0; i <= length; cout << "═", ++i);
//		cout << "╣";
//	}
//	//铅垂线
//	else {
//		int x = rect->locX + startX;
//		int y = (rect->locY << 1) + startY;
//		cout << "╦";
//		for (i = 0; i < length; ++i) {
//			SetCursorPos(++x, y);
//			cout << "║";
//		}
//		SetCursorPos(++x, y);
//		cout << "╩";
//	}
//}

void Display::DrawSplitLine(SplitLine* sp) {
	int x = sp->Transform.locX;
	int y = sp->Transform.locY;
	if (sp->Parent) {
		x += sp->Parent->Transform.locX;
		y += sp->Parent->Transform.locY << 1;
	}
	SetCursorPos(x, y);
	int i;
	int len = sp->GetLength();
	//水平线
	if (sp->IsHorizon()) {
		cout << "╠";
		for (i = 0; i <= len; cout << "═", ++i);
		cout << "╣";
	}
	//铅垂线
	else {
		cout << "╦";
		for (i = 0; i <= len; ++i) {
			SetCursorPos(++x, y);
			cout << "║";
		}
		SetCursorPos(x, y);
		cout << "╩";
	}
}
