#include "GameFrame.h"
int initMenuStartRow = 2;
int initMainFrameRow = 0;
void Clear(int row, int count, int column) {
    int originalRow = row;
    for(int i = 0; i < count; i ++) {
        SetPosition(MARGIN_X+1, row++);
        for(int j = 0; j < column; j ++) {
            printf(" ");
        }
    }
    SetPosition(MARGIN_X, originalRow);
}

int ShowWelcome2() {
    int welcom_start_row = 0;
    SetPosition(MARGIN_X, welcom_start_row);
    printf(SEP);
    SetPosition(MARGIN_X, ++welcom_start_row);
    printf("|");
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-5, welcom_start_row);
    printf("欢迎来到岳飞的世界");
    SetPosition(MARGIN_X+OFFSET_X, welcom_start_row);
    printf("|");
    SetPosition(MARGIN_X, ++welcom_start_row);
    printf(SEP);
    return welcom_start_row;
}

int ShowMenu() {
    int menuStartRow = initMenuStartRow;
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
    initMainFrameRow = menuStartRow;
    return menuStartRow;
}

int InitMainFrame() {
    int mainFrameRow = initMainFrameRow;
    for(int i = 0; i < MAIN_FRAME_ROW; i ++) {
        SetPosition(MARGIN_X, ++mainFrameRow);
        printf("|");
        SetPosition(MARGIN_X+OFFSET_X, mainFrameRow);
        printf("|");
    }
    SetPosition(MARGIN_X, ++mainFrameRow);
    printf(SEP);
    return mainFrameRow;
}
