#include "YesUI.h"
int main() {
	Window window = Window();
	window.title(L"YesUI Example Program");
	window.size(300, 186);
	Static(window, L"Text Detector", Font(L"微软雅黑", 30, true), false, "center").place(0, 2, 300, 30);
	Static(window, L"Made by Yeskunkun!", Font(L"微软雅黑", 22), false, "center").place(0, 32, 300, 22);
	Edit ed = Edit(window, L"Hello World!", Font(L"微软雅黑", 26));
	ed.place(20, 66, 260, 30);
	Checkbox ch = Checkbox(window, L"Click to enable detection!", Font(L"微软雅黑", 25), [&]() {
		if (ch.get()) {window.msgbox(L"You checked the checkbox!", L"Checkbox", MB_OK | MB_ICONWARNING);
		}else {window.msgbox(L"You unchecked the checkbox!", L"Checkbox", MB_OK | MB_ICONERROR);}});
	ch.place(20, 100, 260, 30);
	Button(window, L"Detect!", Font(L"微软雅黑", 25, L"Bold"), [&]() {
		if (ch.get()) {window.msgbox(ed.get(), L"Detected text!", MB_OKCANCEL | MB_ICONINFORMATION);}
		else {window.msgbox(L"Please enable detection first!", L"Error", MB_OK | MB_ICONERROR);}},true).place(20, 135, 180, 35);
	Button(window, L"Exit", Font(L"微软雅黑", 25), [&]() {
		if (window.msgbox(L"Won't you play for a while longer?", L"Leave now?", MB_YESNO | MB_ICONINFORMATION) == IDYES) {
			window.destroy();
			ExitProcess(0);}}).place(204, 135, 76, 35);
	window.mainloop();
	return 0;
}
