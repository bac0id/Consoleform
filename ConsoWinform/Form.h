#pragma once
#ifndef __FORM_H
#define __FORM_H
#include <new>
#include <string>
#include <vector>
#include "Rect.h"
#include "Control.h"
#include "Text.h"
#include "SplitLine.h"
//窗口类
class Form : public Control
{
public:
	//构造器
	Form();
	Form(int sizeX, int sizeY, int locX, int locY);
	Form(int sizeX, int sizeY, int locX, int locY, Text* texts, int textCnt);
	Form(int sizeX, int sizeY, int locX, int locY, Control* parent);
	Form(int sizeX, int sizeY, int locX, int locY, Control* parent, Text* texts, int textCnt);
	Form(Rect& transform);
	Form(Rect& transform, Text* texts, int textCnt);
	Form(Rect& transform, Control* parent);
	Form(Rect& transform, Control* parent, Text* texts, int textCnt);

	//文本
	Text* Texts;
	//文本数量
	int TextCnt;
	//显示窗口
	void Draw();
	void Draw(bool fill);

};
#endif // !__FORM_H
