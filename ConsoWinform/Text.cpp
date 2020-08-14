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
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, 0, 0 };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = nullptr;
	new (this)Text(0, 0, nullptr, "", (int)ConsoleFGColor::White);
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
返回：	Text实例
*/
Text::Text(int x, int y)
{
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = nullptr;
	new (this)Text(x,y, nullptr, "", (int)ConsoleFGColor::White);
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
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = color;
	//this->Parent = nullptr;
	//new (this)Text(x, y, nullptr, "", color);
	new (this)Text(x, y, nullptr, "", color);
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
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = nullptr;
	new (this)Text(x, y, nullptr, text, (int)ConsoleFGColor::White);
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
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT,x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = nullptr;
	new (this)Text(x, y, nullptr, text, (int)ConsoleFGColor::White);
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
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = color;
	//this->Parent = nullptr;
	new (this)Text(x, y, nullptr, text, color);
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
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = color;
	//this->Parent = nullptr;
	new (this)Text(x, y, nullptr, text, color);
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
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = parent;
	new (this)Text(x, y, parent, "", (int)ConsoleFGColor::White);
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		parent: 父组件的位置信息
		color: 文本颜色
返回：	Text实例
*/
Text::Text(int x, int y, Component* parent, int color)
{
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = color;
	//this->Parent = parent;
	new (this)Text(x, y, parent, "", color);
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
		parent: 父组件的位置信息
返回：	Text实例
*/
Text::Text(int x, int y, Component* parent, const char* text)
{
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = parent;
	new (this)Text(x, y, parent, text, (int)ConsoleFGColor::White);
}
/*
文本的构造函数
参数：	x: 起点X坐标
		y: 起点Y坐标
		text: 文本内的字符串
		parent: 父组件的位置信息
返回：	Text实例
*/
Text::Text(int x, int y, Component* parent, string text)
{
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = parent;
	new (this)Text(x, y, parent, text, (int)ConsoleFGColor::White);
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
Text::Text(int x, int y, Component* parent, const char* text, int color)
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
Text::Text(int x, int y, Component* parent, string text, int color)
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
	Clear();
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

void Text::Input()
{
	this->Focus();
	string buf;
	// you can replace cin with another INPUT procedure
	cin >> buf;
	SetStr(buf);
}

/*
清空文本
参数：	无
返回：	无
*/
void Text::Clear()
{
	string s(this->Str.size(), ' ');
	this->Str = s;
	Draw();
	this->Str = "";
}
/*
绘制文本
参数：	无
返回：	无
*/
void Text::Draw()
{
	//Display::DrawLabel(this);
	int x = this->Transform.locX;
	int y = this->Transform.locY;
	Component* cur = this->Parent;
	while (cur != nullptr) {
		x +=cur->Transform.locX;
		y +=cur->Transform.locY << 1;
		cur = cur->Parent;
	}
	Display::SetColor(this->GetColor());
	Display::DrawString(x, y, this->GetStr());
	Display::ResetColor();
}