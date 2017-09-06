#include "Login.h"
extern int initMenuStartRow;
extern int initMainFrameRow;
extern Player* loginPlayer;
int login_x = 0;
int login_y = 0;
int loginMenuSize = 0;
char* playerFile = "player.data";
/* 显示首页主菜单 */
void InitIndexMenu() {
    int menuStartRow = initMenuStartRow;
    char loginMenu[][50]={{"登陆"}, {"注册"}};
    Clear(++menuStartRow, 2, OFFSET_X-1);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X, menuStartRow);
    printf("请选择");
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-7, ++menuStartRow);
    loginMenuSize = sizeof(loginMenu)/sizeof(loginMenu[0]);
    for(int i = 0; i < loginMenuSize; i ++) {
        char menu[50];
        strcpy(menu, loginMenu[i]);
        if(login_x == i) {
            SetColor(0, 7);
        }
        printf("%d、%s", i+1, menu);
        ResetColor();
        printf("     ");
    }
}
int ShowIndexMenu() {
    char key = 0;
    int isSuccess = 0;
    while(1) {
        key = getch();
        if(key == 13) {
            isSuccess = ProcessIndex();
            if(isSuccess > 0) {
                break;
            }
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
                printf("输入错误");
                continue;
            }
            InitIndexMenu();
        }
    }
    return isSuccess;
}

int ProcessIndex() {
    if(login_x == 0) {  //显示登陆
        return ShowLogin();
    } else {
        int i = ShowRegist();   //显示注册
        if(i > 0) {
            login_x = 0;
            InitIndexMenu();
            return ShowLogin();
        }
    }
}

int ShowLogin() {
    char loginName[50];
    char password[50];
    char passCh = 0;
    int passChCount = 0;
    int row = initMainFrameRow;
    Clear(++row, MAIN_FRAME_ROW-1, OFFSET_X-1);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-10, row++);
    printf("请大侠输入账号和密码，按回车登陆");
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, ++row);
    printf("账号：");
    gets(loginName);
    ++row;
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, ++row);
    printf("密码：");
    while((passCh = getch()) != 13 && passChCount < 49) {
        password[passChCount++] = passCh;
    }
    password[passChCount]='\0';
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X, ++row);
    int isSuccess = Login(loginName, password);
    return isSuccess;
}

int Login(char loginName[], char password[]) {
    FILE* file = fopen(playerFile, "rb");
    Player* player = (Player*)malloc(sizeof(Player));
    int isSuccess = 0;
    while(1 <= fread(player, sizeof(Player), 1, file)) {
        if(0 == strcmp(player->loginName, loginName) && 0 == strcmp(player->password, password)) {
            loginPlayer = player;
            printf("登录成功");
            isSuccess = 1;
            break;
        }
    }
    fclose(file);
    if(isSuccess <= 0) {
        printf("登录失败，账号密码错误");
    }
    return isSuccess;
}

int ShowRegist() {
    int isSuccess = 0;
    char name[50];
    char loginName[50];
    char password[50];
    char password2[50];
    char passChar = 0;
    int passChCount = 0;
    int row = initMainFrameRow;
    Clear(++row, MAIN_FRAME_ROW-1, OFFSET_X-1);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-7, row++);
    printf("请大侠填写以下信息");
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, ++row);
    printf("姓名：");
    gets(name);
    ++row;
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, ++row);
    if(strlen(name) == 0) {
        printf("用户名为空");
        return isSuccess;
    }
    printf("账号：");
    gets(loginName);
    ++row;
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, ++row);
    if(strlen(loginName) == 0) {
        printf("登录账号为空");
        return isSuccess;
    }
    printf("密码：");
    while((passChar = getch()) != 13 && passChCount < 49) {
        password[passChCount++] = passChar;
    }
    password[passChCount]='\0';

    ++row;
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-11, ++row);
    if(strlen(password) == 0) {
        printf("密码为空");
        return isSuccess;
    }
    printf("重新输入密码：");
    passChCount = 0;
    while((passChar = getch()) != 13 && passChCount < 49) {
        password2[passChCount++] = passChar;
    }
    password2[passChCount]='\0';

    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, ++row);
    if(strcmp(password, password2) != 0) {
        printf("两次输入的密码不一致");
        return isSuccess;
    }
    FILE* file = fopen(playerFile, "rb");
    Player* oldPlayer = (Player*) malloc(sizeof(Player));
    int isDuplicate = 1;
    int count = 0;
    while(1 <= fread(oldPlayer, sizeof(Player), 1, file)) {
        if(strcmp(oldPlayer->loginName, loginName) == 0) {
            printf("登录账号已存在，请重新输入");
            isDuplicate = 0;
            break;
        }
        if(strcmp(oldPlayer->name, name) == 0) {
            printf("大侠名字已被使用，请重新输入");
            isDuplicate = 0;
            break;
        }
        count ++;
    }

    fclose(file);
    if(isDuplicate) {
        Player* player = (Player*) malloc(sizeof(Player));
        strcpy(player->name, name);
        strcpy(player->loginName, loginName);
        strcpy(player->password, password);
        player->id = count;
        player->exp = 0;
        player->hp = 100;
        player->level = 1;
        player->maxAttack = 5;
        player->maxDefence = 5;
        player->maxExp = 20;
        player->maxHp = 100;
        player->maxMp = 50;
        player->minAttack = 5;
        player->minDefence = 5;
        player->money = 100;
        player->mp = 50;
        file = fopen(playerFile, "ab+");    //在文件末尾追加
        fwrite(player, sizeof(Player), 1, file);
        printf("注册成功");
        isSuccess = 1;
    }
    return isSuccess;

}
