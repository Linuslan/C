#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "GameLib.h"
#include "GameFrame.h"
int x = 0;
int y = 0;
int main() {
    /*int max_x = 0;
    int max_y = 0;
    char key = 0;
    Init();
    SetTitle("说岳全传");
    SetColor(10, 0);
    ShowWelcome();
    RefreshMap(x, y);
    RefreshInfo();
    InitMenu();
    GetMapSize(&max_x, &max_y);
    while(1) {
        key = getch();
        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5') {
            ProcessMenu(key);
        } else {
            if(key == VK_UP || key == 72) {
                y --;
                if(y < 0) {
                    y = max_y-1;
                }
            } else if(key == VK_RIGHT || key == 77) {
                x ++;
                if(x >= max_x) {
                    x = 0;
                }
            } else if(key == VK_DOWN || key == 80) {
                y ++;
                if(y >= max_y) {
                    y = 0;
                }
            } else if(key == VK_LEFT || key == 75) {
                x --;
                if(x < 0) {
                    x = max_x-1;
                }
            } else if(key != -32) {
                printf("输入错误");
                InitMenu();
                continue;
            }
            RefreshMap(x, y);
        }
    }*/
    //SavePlayers();
    //ReadPlayer();
    ShowWelcome2();
    ShowMenu();
    return 0;
}
