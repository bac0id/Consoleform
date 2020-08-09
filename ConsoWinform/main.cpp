#include <iostream>
#include <vector>
#include <conio.h>
#include <sstream>

#include "Display.h"
using namespace std;

int main()
{
	Text* txts = new Text[3]{
		Text(1,2,"가가"),
		Text(2,6,"1234"),
		Text(4,10,"가11가"),
	};
	Form* fm = new Form(8, 6, 0, 0, txts, 3);
	SplitLine* sp = new SplitLine(true, 3, fm);
	fm->Draw(false);
	sp->Draw();
	
	Text* txts2 = new Text[3]{
		Text(1,2,"가가1"),
		Text(2,2,"가가2"),
	};
	Form* fm2 = new Form(5, 20, 10, 2, txts2, 3);
	SplitLine* sp2 = new SplitLine(true, 3, fm2);
	SplitLine* sp3 = new SplitLine(true, 4, fm2, 36);
	fm2->Draw(false);
	sp2->Draw();
	sp3->Draw();

	_getch();
}