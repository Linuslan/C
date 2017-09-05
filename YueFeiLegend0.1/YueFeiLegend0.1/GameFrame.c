#include "GameFrame.h"
int menuStartRow = 2;
void Clear(int row, int count) {
    int originalRow = row;
    for(int i = 0; i < count; i ++) {
        SetPosition(MARGIN_X, row++);
        printf(CLEAR_SPACE);
    }
    SetPosition(MARGIN_X, originalRow);
}

int ShowWelcome2() {
    int welcom_start_row = 0;
    SetPosition(MARGIN_X, welcom_start_row);
    printf(SEP);
    SetPosition(MARGIN_X, ++welcom_start_row);
    printf("|");
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X, welcom_start_row);
    printf("欢迎来到岳飞的世界");
    SetPosition(MARGIN_X+OFFSET_X, welcom_start_row);
    printf("|");
    SetPosition(MARGIN_X, ++welcom_start_row);
    printf(SEP);
    return welcom_start_row;
}

int ShowMenu() {
    SetPosition(MARGIN_X, ++menuStartRow);
    printf("|");
    SetPosition(MARGIN_X + OFFSET_X, menuStartRow);
    printf("|");
    SetPosition(MARGIN_X, ++menuStartRow);
    printf("|");
    SetPosition(MARGIN_X + OFFSET_X, menuStartRow);
    printf("|");
    SetPosition(MARGIN_X, ++menuStartRow);
    printf(SEP);
    return menuStartRow;
}

void InitLoginMenu() {
    Clear(++menuStartRow, 2);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X, menuStartRow);
    printf("请选择");
    SetPosition(MARGIN_X+ROW_OFFSET_X, ++menuStartRow);
    printf("1、登录\t");
}
