#include <stdio.h>
#include <stdlib.h>
#include "GameLib.h"
void SetTitle(char* title) {
    SetConsoleTitle(title);
}

//0:黑色; 1:蓝色; 2:绿色; 3:浅绿色; 4:红色; 5:紫色; 6:黄色; 7:白色; 8:灰色; 9:淡蓝色;
//10:淡绿色; 11:淡浅绿色; 12:淡红色; 13:淡紫色; 14:淡黄色; 15:亮白色
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
