#include <stdio.h>
#include <stdlib.h>
#include "GameLib.h"
void SetWindow(char* title, int width, int height) {
    SetConsoleTitle(title);
    HWND hwnd = FindWindow(NULL, title);
    if(hwnd) {
        SetWindowPos(hwnd, HWND_TOPMOST, 300, 100, width, height, SWP_SHOWWINDOW);
    }
}
