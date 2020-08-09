#include <conio.h>
#include "Display.h"
using namespace std;
void run_example_1()
{
	// Show the cursor
	Display::SetCursorVisibility(true);
	// The account and password of a certain user
	const string acc = "user1";
	const string pw = "123123";
	// Initialize the Login window
	Text* txsLogin = new Text[6]{
		Text(2, 12,	"Login"),
		Text(4, 4,	"Username: "),
		Text(5, 4,	"Password: "),
		Text(4, 14),
		Text(5, 14),
		Text(7, 4,	"Welcome to XXX system."),
	};
	Form* fmLogin = new Form(8, 13, 2, 10, txsLogin, 6);
	fmLogin->Draw(false);
	for (;;) {
		// Input strings and save it into a text instance
		fmLogin->Texts[3].Input();
		fmLogin->Texts[4].Input();
		// Check inputs
		if (fmLogin->Texts[3].GetStr() == acc && fmLogin->Texts[4].GetStr() == pw) {
			fmLogin->Texts[5].SetStr("Login successfully.");
			fmLogin->Texts[5].SetColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		}
		else {
			fmLogin->Texts[5].SetStr("Incorrect input!");
			fmLogin->Texts[5].SetColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
			fmLogin->Texts[3].Clear();
			fmLogin->Texts[4].Clear();
		}
	}
}
void run_example_2()
{
	// Hide the cursor
	Display::SetCursorVisibility(false);
	// Initialize
	Text* txsProf = new Text[9]{
		Text(2, 20,	"Player Profile"),
		Text(4, 20, "Tanaka"),
		Text(5, 20, "Tokyo, Japan"),
		Text(7, 20, "I love anime and games!"),

		Text(12, 4, "Comments"),
		Text(15, 13, "Mori (*VIP)",FOREGROUND_RED | FOREGROUND_INTENSITY),
		Text(16, 13, "+rep, good player"),
		Text(19, 13, "Obama"),
		Text(20, 13, "report this cheater plz"),
	};
	Form* fmProf = new Form(22, 22, 2, 5, txsProf, 9);
	Text* txsAvatar = new Text[3]{
		Text(2, 5, " ", BACKGROUND_GREEN),
		Text(2, 9, " ", BACKGROUND_GREEN),
		Text(4, 7, "__", FOREGROUND_GREEN),
	};
	Form* fmAvatar = new Form(5, 5, 2, 2, fmProf, txsAvatar, 3);
	SplitLine* sp = new SplitLine(true, 10, fmProf);
	Form* fmCmt1 = new Form(2, 2, 14, 2, fmProf);
	Form* fmCmt2 = new Form(2, 2, 18, 2, fmProf);
	// Draw these objects in a certain layer order
	// please consider the split line
	fmProf->Draw(false);
	fmAvatar->Draw(false);
	sp->Draw();
	fmCmt1->Draw(false);
	fmCmt2->Draw(false);
}
int main()
{
	run_example_2();
	_getch();
	return 0;
}

//
//	Text* txts = new Text[3]{
//		Text(1,2,"Hello World!"),
//		Text(2,6,"1234"),
//		Text(4,10,"°¡11°¡"),
//	};
//	Form* fm = new Form(8, 6, 0, 0, txts, 3);
//	SplitLine* sp = new SplitLine(true, 3, fm);
//	fm->Draw(false);
//	sp->Draw();
//
//
//	_getch();
//}