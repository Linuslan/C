#include "Game.h"
#include "GameLib.h"
#define MARGIN_X 33
#define OFFSET_X 77
#define SEP "------------------------------------------------------------------------------"
int welcom_start_row = 0;
int map_start_row = 0;
int info_start_row = 0;
int menu_start_row = 0;
int init_menu_start_row = 0;
int init_info_start_row = 0;
Player* loginPlayer = NULL;

/* ��ʼ�������Ϣ */
Player players[] = {
    {1, "�Է���", "123456", .level=1, .maxExp=20, .exp=0, .maxHp=100, .maxMp=50, .minAttack=5, .maxAttack=10, .minDefence=5, .maxDefence=10, .weapon={}, .armor={}, .martial={}, .coord={}, .bag={}},
    {2, "GM", "123456", .level=9999, .maxExp=65535, .exp=65535, .maxHp=65535, .maxMp=65535, .minAttack=65535, .maxAttack=65535, .minDefence=65535, .maxDefence=65535, .weapon={}, .armor={}, .martial={}, .coord={}, .bag={}}
};
/* ��ʼ������ */
Prop props[] = {
    {
        1, "���������", WEAPON, .level=1, .minAttack=5, .maxAttack=10, .price=100, .stock=50, .desc="����ר��"
    }, {
        2, .name="�ƾɵĻ���", ARMOR, .level=2, .minDefence=5, .maxDefence=10, .price=500, .stock=50, .desc="����ר��"
    }, {
        3, .name="ľǹ", WEAPON, .level=5, .minAttack=10, .maxAttack=15, .price=500, .stock=50, .desc="�ʺϳ��뽭��������"
    }
};

/* ��ʼ����ͼ */
Map maps[][8] = {
    {
        {
            .id=1, .name="�����", .fullName="�������ڻ��������", .coord={0, 0}, .desc="���ɶ�ʱƯ������"
        },
        {
            .id=2, .name="�ڻ���", .fullName="�������ڻ���", .coord={1, 0}, .desc="�������ڻ��أ�����������"
        },
        {
            .id=3, .name="������", .fullName="������", .coord={2, 0}, .desc="������"
        },
        {
            .id=4, .name="������", .fullName="����������", .coord={3, 0}, .desc="����������"
        },
        {
            .id=5, .name="����", .fullName="����", .coord={4, 0}, .desc="����"
        },
        {
            .id=6, .name="��Ȫɽ", .fullName="������Ȫɽ", .coord={5, 0}, .desc=""
        },
        {
            .id=7, .name="��Ȫ��", .fullName="��Ȫ��", .coord={6, 0}, .desc=""
        },
        {
            .id=8, .name="�Ҳݸ�", .fullName="�Ҳݸ�", .coord={7, 0}, .desc=""
        }
    },
    {
        {
            .id=1, .name="�����1", .fullName="�������ڻ��������", .coord={0, 1}, .desc="���ɶ�ʱƯ������"
        },
        {
            .id=2, .name="�ڻ���2", .fullName="�������ڻ���", .coord={1, 1}, .desc="�������ڻ��أ�����������"
        },
        {
            .id=3, .name="������3", .fullName="������", .coord={2, 1}, .desc="������"
        },
        {
            .id=4, .name="������4", .fullName="����������", .coord={3, 1}, .desc="����������"
        },
        {
            .id=5, .name="����5", .fullName="����", .coord={4, 1}, .desc="����"
        },
        {
            .id=6, .name="��Ȫɽ6", .fullName="������Ȫɽ", .coord={5, 1}, .desc=""
        },
        {
            .id=7, .name="��Ȫ��7", .fullName="��Ȫ��", .coord={6, 1}, .desc=""
        },
        {
            .id=8, .name="�Ҳݸ�8", .fullName="�Ҳݸ�", .coord={7, 1}, .desc=""
        }
    }

};

void Init() {
    map_start_row = 3;
    init_info_start_row = map_start_row + sizeof(maps) / sizeof(maps[0]) + 1;
    init_menu_start_row = init_info_start_row + 11;
    loginPlayer = &players[0];
}

void ShowWelcome() {
    SetPosition(MARGIN_X, welcom_start_row);
    printf(SEP);
    SetPosition(MARGIN_X, ++welcom_start_row);
    printf("|");
    SetPosition(MARGIN_X+30, welcom_start_row);
    printf("��ӭ�������ɵ�����");
    SetPosition(MARGIN_X+77, welcom_start_row);
    printf("|");
    SetPosition(MARGIN_X, ++welcom_start_row);
    printf(SEP);
}

void RefreshMap(int x, int y) {
    int map_y = map_start_row;
    int i, j;
    int size = sizeof(maps) / sizeof(maps[0]);
    int size2 = sizeof(maps[0]) / sizeof(Map);
    for(i = 0; i < size; i ++) {
        SetPosition(MARGIN_X, map_y);
        printf("|");
        SetPosition(MARGIN_X+4, map_y);
        for(j = 0; j < size2; j ++) {
            Map map = maps[i][j];
            if(x == j && y == i) {
                SetColor(7, 4);
            }
            printf("%-9s", map.name);
            SetColor(10, 0);
        }
        SetPosition(MARGIN_X+77, map_y++);
        printf("|");
    }
    SetPosition(MARGIN_X, map_y);
    printf(SEP);
}

void RefreshInfo() {
    info_start_row = init_info_start_row;
    for(int i = 0; i < 10; i ++) {
        SetPosition(MARGIN_X, info_start_row);
        printf("|");
        for(int j = 0; j < OFFSET_X-1; j ++) {
            printf(" ");
        }
        SetPosition(MARGIN_X+OFFSET_X, info_start_row++);
        printf("|");
    }
    SetPosition(MARGIN_X, info_start_row);
    printf(SEP);
}

void InitMenu() {
    menu_start_row = init_menu_start_row;
    SetPosition(MARGIN_X, menu_start_row);
    printf("��Ϸ�˵�");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("1���鿴����");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("2���۲���Χ");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("3�����ܲ�");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("4������װ��");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("                                                                                                              ");
    SetPosition(MARGIN_X, menu_start_row);
    printf("��ѡ��������߶�:");
}

void GetMapSize(int* x, int* y) {
    *y = sizeof(maps) / sizeof(maps[0]);
    *x = sizeof(maps[0]) / sizeof(Map);
}

void ProcessMenu(char key) {
    if(key == '1') {    //ִ���������չʾ
        ShowPlayer();
    }
}

void ShowPlayer() {
    info_start_row = init_info_start_row;
    RefreshInfo();
    SetPosition(MARGIN_X+20, info_start_row++);
    printf("��������");
    SetPosition(MARGIN_X+5, info_start_row++);
    printf("������%s", loginPlayer->name);
}

