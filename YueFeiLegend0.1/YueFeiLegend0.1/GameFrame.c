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
    printf("»¶Ó­À´µ½ÔÀ·ÉµÄÊÀ½ç");
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
Map menuMap[] = {
    {.id=1, .name="µÇÂ¼", .coord={0, 0}},
    {.id=2, .name="×¢²á", .coord={0, 1}
};
void InitLoginMenu() {
    Clear(++menuStartRow, 2);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X, menuStartRow);
    printf("ÇëÑ¡Ôñ");
    SetPosition(MARGIN_X+ROW_OFFSET_X, ++menuStartRow);
    int size = sizeof(menuMap)/sizeof(Map);
    for(int i = 0; i < size; i ++) {

    }
}
