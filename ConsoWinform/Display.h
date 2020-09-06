#pragma once
#ifndef __DISPLAY_H
#define __DISPLAY_H
#include <string>
#include <Windows.h>
#include "ConsoleColor.h"
#include "Rect.h"
#include "Form.h"
#include "Text.h"
#include "SplitLine.h"
using namespace std;
class Text;
class SplitLine;
//显示控制类
static class Display
{
public:
	//设置光标坐标
	static void SetCursorPos(int x, int y);
	//获得光标坐标
	static COORD GetCursorPos();
	//设置光标可见度
	static void SetCursorVisibility(bool visible);
	//设置窗口尺寸
	static void SetConsoleSize(int x, int y);
	//设置字体颜色
	static void SetColor(int color);
	//重置字体颜色
	static void ResetColor();
	//清屏
	static void Clear();
	//在原点绘制指定矩形
	static void DrawRect(int x, int y);
	//在指定坐标绘制指定矩形
	static void DrawRect(int x, int y, int offsetX, int offsetY);
	//在指定坐标绘制指定矩形
	static void DrawRect(int x, int y, int offsetX, int offsetY, bool fill);
	//绘制矩形
	static void DrawRect(Rect* rect);
	//绘制矩形
	static void DrawRect(Rect* rect, bool fill);
	//在指定坐标打印字符串
	static void DrawString(int x, int y, char* str);
	//在指定坐标打印字符串
	static void DrawString(int x, int y, string str);
	//在指定矩形内的指定相对坐标打印字符串
	static void DrawString(Rect* rect, int x, int y, char* str);
	//在指定矩形内的指定相对坐标打印字符串
	static void DrawString(Rect* rect, int x, int y, string str);
	//绘制文本
	static void DrawLabel(Text* text);
	//在指定矩形内的绘制文本
	static void DrawLabel(Rect* rect, Text* text);
	//绘制分割线
	static void DrawSplitLine(SplitLine* sp);
};
#endif // !__DISPLAY_H
