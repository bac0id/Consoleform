#include <string>

#include "Display.h"
#include "Form.h"
using namespace std;

/// <summary>
/// 窗口类
/// </summary>
Form::Form() {
	Rect r{ 0, 0, 0, 0 };
	new (this)Form(r, nullptr, nullptr, 0);
}
/// <summary>
/// 窗口类
/// </summary>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <param name="locX"></param>
/// <param name="locY"></param>
Form::Form(int sizeX, int sizeY, int locX, int locY) {
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, nullptr, nullptr, 0);
}
/// <summary>
/// 窗口类
/// </summary>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <param name="locX"></param>
/// <param name="locY"></param>
/// <param name="texts">Form内的文本</param>
/// <param name="textCnt">Form内的文本数量</param>
Form::Form(int sizeX, int sizeY, int locX, int locY, Text* texts, int textCnt) {
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, nullptr, texts, textCnt);
}
/// <summary>
/// 窗口类
/// </summary>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <param name="locX"></param>
/// <param name="locY"></param>
/// <param name="parent">父控件</param>
Form::Form(int sizeX, int sizeY, int locX, int locY, Control* parent) {
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, parent, nullptr, 0);
}
/// <summary>
/// 窗口类
/// </summary>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <param name="locX"></param>
/// <param name="locY"></param>
/// <param name="parent">父控件</param>
/// <param name="texts">Form内的文本</param>
/// <param name="textCnt">Form内的文本数量</param>
Form::Form(int sizeX, int sizeY, int locX, int locY, Control* parent, Text* texts, int textCnt) {
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, parent, texts, textCnt);
}
/// <summary>
/// 窗口类
/// </summary>
/// <param name="transform">位置信息</param>
Form::Form(Rect& transform) {
	new (this)Form(transform, nullptr, nullptr, 0);
}
/// <summary>
/// 窗口类
/// </summary>
/// <param name="transform">位置信息</param>
/// <param name="texts">Form内的文本</param>
/// <param name="textCnt">Form内的文本数量</param>
Form::Form(Rect& transform, Text* texts, int textCnt) {
	new (this)Form(transform, nullptr, texts, textCnt);
}
Form::Form(Rect& transform, Control* parent) {
	new (this)Form(transform, parent, nullptr, 0);
}
Form::Form(Rect& transform, Control* parent, Text* texts, int textCnt) {
	this->Transform = transform;
	this->Parent = parent;
	this->Texts = texts;
	for (int i = 0; i < textCnt; ++i) {
		(texts + i)->Parent = this;
	}
	this->TextCnt = textCnt;
}
/// <summary>
/// 显示窗口
/// </summary>
void Form::Draw() {
	Draw(true);
}
/// <summary>
/// 显示窗口
/// </summary>
/// <param name="fill">是否填充内部</param>
void Form::Draw(bool fill) {
	int locX = this->Transform.locX;
	int locY = this->Transform.locY;
	Control* cur = this->Parent;
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
	} else {
		Display::DrawRect(&this->Transform, fill);
	}
	for (int i = 0; i < this->TextCnt; ++i) {
		(Texts + i)->Draw();
	}
}