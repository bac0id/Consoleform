#pragma once
#ifndef __Text_h
#define __Text_h
#include <string>
#include "Component.h"
#define TEXT_WIDTH_DEFAULT 16
using namespace std;
//文本类
class Text : public Component
{
public:
	//构造器
	Text();
	Text(int x, int y);
	Text(int x, int y, int color);
	Text(int x, int y, const char* text);
	Text(int x, int y, string text);
	Text(int x, int y, const char* text, int color);
	Text(int x, int y, string text, int color);
	Text(int x, int y, Component* parent);
	Text(int x, int y, Component* parent, int color);
	Text(int x, int y, Component* parent, const char* text);
	Text(int x, int y, Component* parent, string text);
	Text(int x, int y, Component* parent, const char* text, int color);
	Text(int x, int y, Component* parent, string text, int color);
	//得到文本内的字符串
	string GetStr();
	//设置文本内的字符串
	void SetStr(string str);
	//得到文本颜色
	int GetColor();
	//设置文本颜色
	void SetColor(int color);
	//聚焦，将光标移动到文本内
	void Focus();
	//在文本内输入
	void Input();
	//清空文本
	void Clear();
	//绘制文本
	void Draw();
private:
	//文本
	string Str;
	//颜色
	int Color;
};
#endif // !__Text_h