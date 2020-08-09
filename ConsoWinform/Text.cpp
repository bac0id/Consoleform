#include <string>

#include "Text.h"
#include "Display.h"
using namespace std;
/*
文本的构造函数
参数：	无
返回：	Text实例
*/
Text::Text()
{
	this->Str = "";
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, 0, 0 };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = nullptr;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
返回：	Text实例
*/
Text::Text(int x, int y)
{
	this->Str = "";
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = nullptr;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		parent: 父组件的位置信息
返回：	Text实例
*/
Text::Text(int x, int y, Component* parent)
{
	this->Str = "";
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = parent;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
返回：	Text实例
*/
Text::Text(int x, int y, const char* text)
{
	//this->Str = string(text);
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = nullptr;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
返回：	Text实例
*/
Text::Text(int x, int y, string text)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT,x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = nullptr;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
		parent: 父组件的位置信息
返回：	Text实例
*/
Text::Text(int x, int y, const char* text, Component* parent)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = parent;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
		parent: 父组件的位置信息
返回：	Text实例
*/
Text::Text(int x, int y, string text, Component* parent)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = parent;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		color: 文本颜色
返回：	Text实例
*/
Text::Text(int x, int y, int color)
{
	this->Str = "";
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = nullptr;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
		color: 文本颜色
返回：	Text实例
*/
Text::Text(int x, int y, const char* text, int color)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = nullptr;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
		color: 文本颜色
返回：	Text实例
*/
Text::Text(int x, int y, string text, int color)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = nullptr;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
		color: 文本颜色
		parent: 父组件的位置信息
返回：	Text实例
*/
Text::Text(int x, int y, const char* text, int color, Component* parent)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = parent;
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
		color: 文本颜色
		parent: 父组件的位置信息
返回：	Text实例
*/
Text::Text(int x, int y, string text, int color, Component* parent)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = parent;
}
/*
得到文本内的字符串
参数：	无
返回：	文本内的字符串
*/
string Text::GetStr()
{
	return this->Str;
}
/*
设置文本内的字符串
参数：	str: 字符串
返回：	无
*/
void Text::SetStr(string str)
{
	this->Str = str;
	Draw();
}
/*
得到文本颜色
参数：	无
返回：	文本颜色
*/
int Text::GetColor()
{
	return this->Color;
}
/*
设置文本颜色
参数：	color: 颜色
返回：	无
*/
void Text::SetColor(int color)
{
	this->Color = color;
	Draw();
}

void Text::Focus()
{
	if (!this->Parent) {
		Display::SetCursorPos(this->Transform.locX, this->Transform.locY);
	}
	else {
		Display::SetCursorPos(this->Transform.locX + this->Parent->Transform.locX,
			this->Transform.locY + (this->Parent->Transform.locY << 1));
	}
}

/*
清空文本
参数：	无
返回：	无
*/
void Text::Clear()
{
	//此处不严谨，
	//应该以transform.Y的长度来填充文本
	SetStr("");
}
/*
绘制文本
参数：	无
返回：	无
*/
void Text::Draw()
{
	Display::DrawLabel(this);
}