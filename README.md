# Consoleform
A console version of simplified Winform / 控制台里的简易 Winform
## Examples
### Login Form
This simple example will show you how a `Form` is created and the interactivity of it as well.
```c++
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
	// Show the cursor
	Display::SetCursorVisibility(true);
	// Input strings and save it into a text instance
	fmLogin->Texts[3].Input();
	fmLogin->Texts[4].Input();
	Display::SetCursorVisibility(false);
	// Check inputs
	if (fmLogin->Texts[3].GetStr() == acc && fmLogin->Texts[4].GetStr() == pw) {
		fmLogin->Texts[5].SetStr("Login successfully.");
		fmLogin->Texts[5].SetColor((int)ConsoleFGColor::Green);
		break;
	}
	else {
		fmLogin->Texts[5].SetStr("Incorrect input!");
		fmLogin->Texts[5].SetColor((int)ConsoleFGColor::Red);
		fmLogin->Texts[3].Clear();
		fmLogin->Texts[4].Clear();
	}
}

```
The output will be like...

![Picture of a classic login form](https://github.com/bac0id/Consoleform/blob/master/screenshot_example_1.png)
### Player Profile
The following example shows that `Form` is able to be nested. With some complex combinations, the possibilities are limitless.
```C++
// Hide the cursor
Display::SetCursorVisibility(false);
// Initialize
Text* txsProf = new Text[9]{
	Text(2, 20,	"Player Profile"),
	Text(4, 20, "Tanaka"),
	Text(5, 20, "Tokyo, Japan"),
	Text(7, 20, "I love anime and games!"),

	Text(12, 4, "Comments"),
	Text(15, 13, "Mori (*VIP)",(int)ConsoleFGColor::Red),
	Text(16, 13, "+rep, good player"),
	Text(19, 13, "Obama"),
	Text(20, 13, "report this cheater plz"),
};
Form* fmProf = new Form(22, 22, 2, 5, txsProf, 9);
Text* txsAvatar = new Text[3]{
	Text(2, 5, " ", (int)ConsoleBGColor::Green),
	Text(2, 9, " ", (int)ConsoleBGColor::Green),
	Text(4, 7, "__", (int)ConsoleFGColor::Green),
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
```
And the result output is ...

![Picture of a player profile form](https://github.com/bac0id/Consoleform/blob/master/screenshot_example_2.png)
