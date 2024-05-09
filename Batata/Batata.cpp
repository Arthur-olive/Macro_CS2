#include <iostream>
#include <windows.h>

void keyDown(char key) {
	INPUT inputs[1] = {};
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = 'I';

	UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

void keyUP(char key) {
	INPUT inputs[1] = {};
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = 'I';
	inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;

	UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}
int main() {

	while (true) {
		if (GetKeyState(VK_SPACE) & 0x8000) {
			keyDown('i');
			Sleep(15);
			keyUP('i');
			Sleep(15);
		}
	}
}