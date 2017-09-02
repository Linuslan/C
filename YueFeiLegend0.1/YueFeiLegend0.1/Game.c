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

/* 初始化玩家信息 */
Player players[] = {
    {1, "赵飞云", "123456", .level=1, .maxExp=20, .exp=0, .maxHp=100, .maxMp=50, .minAttack=5, .maxAttack=10, .minDefence=5, .maxDefence=10, .weapon={}, .armor={}, .martial={}, .coord={}, .bag={}},
    {2, "GM", "123456", .level=9999, .maxExp=65535, .exp=65535, .maxHp=65535, .maxMp=65535, .minAttack=65535, .maxAttack=65535, .minDefence=65535, .maxDefence=65535, .weapon={}, .armor={}, .martial={}, .coord={}, .bag={}}
};
/* 初始化道具 */
Prop props[] = {
    {
        1, "生锈的铁剑", WEAPON, .level=1, .minAttack=5, .maxAttack=10, .price=100, .stock=50, .desc="新手专用"
    }, {
        2, .name="破旧的护甲", ARMOR, .level=2, .minDefence=5, .maxDefence=10, .price=500, .stock=50, .desc="新手专供"
    }, {
        3, .name="木枪", WEAPON, .level=5, .minAttack=10, .maxAttack=15, .price=500, .stock=50, .desc="适合初入江湖的少侠"
    }
};

/* 初始化地图 */
Map maps[][8] = {
    {
        {
            .id=1, .name="麒麟村", .fullName="大名府内黄县麒麟村", .coord={0, 0}, .desc="岳飞儿时漂流至此"
        },
        {
            .id=2, .name="内黄县", .fullName="大名府内黄县", .coord={1, 0}, .desc="大名府内黄县，岳飞所在县"
        },
        {
            .id=3, .name="大名府", .fullName="大名府", .coord={2, 0}, .desc="大名府"
        },
        {
            .id=4, .name="汤阴县", .fullName="相州汤阴县", .coord={3, 0}, .desc="相州汤阴县"
        },
        {
            .id=5, .name="相州", .fullName="相州", .coord={4, 0}, .desc="相州"
        },
        {
            .id=6, .name="沥泉山", .fullName="相州沥泉山", .coord={5, 0}, .desc=""
        },
        {
            .id=7, .name="沥泉洞", .fullName="沥泉洞", .coord={6, 0}, .desc=""
        },
        {
            .id=8, .name="乱草岗", .fullName="乱草岗", .coord={7, 0}, .desc=""
        }
    },
    {
        {
            .id=1, .name="麒麟村1", .fullName="大名府内黄县麒麟村", .coord={0, 1}, .desc="岳飞儿时漂流至此"
        },
        {
            .id=2, .name="内黄县2", .fullName="大名府内黄县", .coord={1, 1}, .desc="大名府内黄县，岳飞所在县"
        },
        {
            .id=3, .name="大名府3", .fullName="大名府", .coord={2, 1}, .desc="大名府"
        },
        {
            .id=4, .name="汤阴县4", .fullName="相州汤阴县", .coord={3, 1}, .desc="相州汤阴县"
        },
        {
            .id=5, .name="相州5", .fullName="相州", .coord={4, 1}, .desc="相州"
        },
        {
            .id=6, .name="沥泉山6", .fullName="相州沥泉山", .coord={5, 1}, .desc=""
        },
        {
            .id=7, .name="沥泉洞7", .fullName="沥泉洞", .coord={6, 1}, .desc=""
        },
        {
            .id=8, .name="乱草岗8", .fullName="乱草岗", .coord={7, 1}, .desc=""
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
    printf("欢迎来到岳飞的世界");
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
    printf("游戏菜单");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("1、查看人物");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("2、观察周围");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("3、回总部");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("4、购买装备");
    SetPosition(MARGIN_X, ++menu_start_row);
    printf("                                                                                                              ");
    SetPosition(MARGIN_X, menu_start_row);
    printf("请选择或四周走动:");
}

void GetMapSize(int* x, int* y) {
    *y = sizeof(maps) / sizeof(maps[0]);
    *x = sizeof(maps[0]) / sizeof(Map);
}

void ProcessMenu(char key) {
    if(key == '1') {    //执行玩家属性展示
        ShowPlayer();
    }
}

void ShowPlayer() {
    info_start_row = init_info_start_row;
    RefreshInfo();
    SetPosition(MARGIN_X+20, info_start_row++);
    printf("大侠资料");
    SetPosition(MARGIN_X+5, info_start_row++);
    printf("姓名：%s", loginPlayer->name);
}

