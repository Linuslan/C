#include "Login.h"
extern int initMenuStartRow;
extern int initMainFrameRow;
int login_x = 0;
int login_y = 0;
int loginMenuSize = 0;
/* ��ʾ��ҳ���˵� */
void InitIndexMenu() {
    int menuStartRow = initMenuStartRow;
    char loginMenu[][50]={{"��½"}, {"ע��"}};
    Clear(++menuStartRow, 2, OFFSET_X-1);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X, menuStartRow);
    printf("��ѡ��");
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-7, ++menuStartRow);
    loginMenuSize = sizeof(loginMenu)/sizeof(loginMenu[0]);
    for(int i = 0; i < loginMenuSize; i ++) {
        char menu[50];
        strcpy(menu, loginMenu[i]);
        if(login_x == i) {
            SetColor(0, 7);
        }
        printf("%d��%s", i+1, menu);
        ResetColor();
        printf("     ");
    }
}
void ShowIndexMenu() {
    char key = 0;
    while(1) {
        key = getch();
        if(key == 13) {
            ProcessIndex();
        } else {
            if(key == VK_RIGHT || key == 77) {
                login_x ++;
                if(login_x >= loginMenuSize) {
                    login_x = 0;
                }
            } else if(key == VK_LEFT || key == 75) {
                login_x --;
                if(login_x < 0) {
                    login_x = loginMenuSize-1;
                }
            } else if(key != -32) {
                printf("�������");
                continue;
            }
            InitIndexMenu();
        }
    }
}

void ProcessIndex() {
    if(login_x == 0) {  //��ʾ��½
        ShowLogin();
    } else {
        ShowRegist();   //��ʾע��
    }
}

void ShowLogin() {
    char loginName[50];
    char password[50];
    char passCh = 0;
    int passChCount = 0;
    int row = initMainFrameRow;
    Clear(++row, MAIN_FRAME_ROW-1, OFFSET_X-1);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-10, row++);
    printf("����������˺ź����룬���س���½");
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, ++row);
    printf("�˺ţ�");
    gets(loginName);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, ++row);
    printf("���룺");
    while((passCh = getch()) != 13 && passChCount < 49) {
        password[passChCount++] = passCh;
    }
    password[passChCount]='\0';
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X, ++row);
    Login(loginName, password);
}

void Login(char loginName[], char password[]) {
    FILE* file = fopen("player.data", "rb");
    Player* player = NULL;
    while(1 <= fread(player, sizeof(Player), 1, file)) {
        printf("1111");
        printf("%s", player->loginName);
        if(0 == strcmp(player->loginName, loginName)) {
            printf("��½�ɹ�");
            break;
        }
    }
}

void ShowRegist() {

}
