#include <string>

#include "Display.h"
#include "Form.h"
using namespace std;
/*
窗口类的构造函数
参数：	无
返回：	默认的窗口实例。
*/
Form::Form()
{
	this->Transform = Rect{ 0, 0, 0, 0 };
	this->Parent = nullptr;
	this->Texts = nullptr;
	this->TextCnt = 0;
}
/*
窗口类的构造函数
参数：	x: 高度
		y: 宽度
		startX: 起点X坐标
		startY: 起点Y坐标
返回：	窗口实例。
*/
Form::Form(int sizeX, int sizeY, int locX, int locY)
{
	this->Transform = Rect{ sizeX, sizeY, locX, locY };
	this->Parent = nullptr;
	this->Texts = nullptr;
	this->TextCnt = 0;
}
/*
窗口类的构造函数
参数：	x: 高度
		y: 宽度
		startX: 起点X坐标
		startY: 起点Y坐标
		texts: 窗口内的文本
		textCnt: 窗口内的文本数
返回：	窗口实例。
*/
Form::Form(int sizeX, int sizeY, int locX, int locY, Text* texts, int textCnt)
{
	this->Transform = Rect{ sizeX, sizeY, locX, locY };
	this->Parent = nullptr;
	this->Texts = texts;
	for (int i = 0; i < textCnt; ++i) {
		(texts + i)->Parent = this;
	}
	this->TextCnt = textCnt;
}
Form::Form(int sizeX, int sizeY, int locX, int locY, Component* parent)
{
	this->Transform = Rect{ sizeX, sizeY, locX, locY };
	this->Parent = parent;
	this->Texts = nullptr;
	this->TextCnt = 0;
}
Form::Form(int sizeX, int sizeY, int locX, int locY, Component* parent, Text* texts, int textCnt)
{
	this->Transform = Rect{ sizeX, sizeY, locX, locY };
	this->Parent = parent;
	this->Texts = texts;
	for (int i = 0; i < textCnt; ++i) {
		(texts + i)->Parent = this;
	}
	this->TextCnt = textCnt;
}
/*
窗口类的构造函数
参数：	transform: 位置信息
返回：	窗口实例。
*/
Form::Form(Rect* transform)
{
	this->Transform = *transform;
	this->Parent = nullptr;
	this->Texts = nullptr;
	this->TextCnt = 0;
}
/*
窗口类的构造函数
参数：	transform: 位置信息
		texts: 窗口内的文本
		textCnt: 窗口内的文本数
返回：	窗口实例。
*/
Form::Form(Rect* transform, Text* texts, int textCnt)
{
	this->Transform = *transform;
	this->Parent = nullptr;
	this->Texts = texts;
	for (int i = 0; i < textCnt; ++i) {
		(texts + i)->Parent = this;
	}
	this->TextCnt = textCnt;
}
Form::Form(Rect* transform, Component* parent)
{
	this->Transform = *transform;
	this->Parent = parent;
	this->Texts = nullptr;
	this->TextCnt = 0;
}
Form::Form(Rect* transform, Component* parent, Text* texts, int textCnt)
{
	this->Transform = *transform;
	this->Parent = parent;
	this->Texts = texts;
	for (int i = 0; i < textCnt; ++i) {
		(texts + i)->Parent = this;
	}
	this->TextCnt = textCnt;
}
/*
显示窗口
参数：	无
返回：	无
*/
void Form::Draw()
{
	Draw(true);
}
/*
显示窗口
参数：	fill: 是否填充内部
返回：	无
*/
void Form::Draw(bool fill)
{
	int locX = this->Transform.locX;
	int locY = this->Transform.locY;
	Component* cur = this->Parent;
	if (cur != nullptr) {
		do {
			locX += cur->Transform.locX;
			locY += cur->Transform.locY;
			cur = cur->Parent;
		} while (cur != nullptr);
		Display::DrawRect(this->Transform.sizeX,
			this->Transform.sizeY,
			locX,
			locY,
			fill);
	}
	else
	{
		Display::DrawRect(&this->Transform, fill);
	}
	for (int i = 0; i < this->TextCnt; ++i) {
		(Texts + i)->Draw();
	}
}