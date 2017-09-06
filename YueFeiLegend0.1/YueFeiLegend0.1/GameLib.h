#include <stdio.h>
#include <windows.h>
void SetTitle(char* title);

//0:黑色; 1:蓝色; 2:绿色; 3:浅绿色; 4:红色; 5:紫色; 6:黄色; 7:白色; 8:灰色; 9:淡蓝色;
//10:淡绿色; 11:淡浅绿色; 12:淡红色; 13:淡紫色; 14:淡黄色; 15:亮白色
void SetColor(int foreColor, int backColor);
void ResetColor();

void SetPosition(int x, int y);
