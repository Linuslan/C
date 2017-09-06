#include <stdio.h>
#include <stdlib.h>
#include "GameLib.h"
void SetTitle(char* title) {
    SetConsoleTitle(title);
}

//0:��ɫ; 1:��ɫ; 2:��ɫ; 3:ǳ��ɫ; 4:��ɫ; 5:��ɫ; 6:��ɫ; 7:��ɫ; 8:��ɫ; 9:����ɫ;
//10:����ɫ; 11:��ǳ��ɫ; 12:����ɫ; 13:����ɫ; 14:����ɫ; 15:����ɫ
void SetColor(int foreColor, int backColor) {
    HWND hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hwnd, foreColor+backColor*0x10);
}

void ResetColor() {
    HWND hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hwnd, 7+0*0x10);
}

void SetSelectedColor() {
    HWND hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hwnd, 0+7*0x10);
}

void SetPosition(int x, int y) {
    HWND hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x, y};
    SetConsoleCursorPosition(hwnd, coord);
}
