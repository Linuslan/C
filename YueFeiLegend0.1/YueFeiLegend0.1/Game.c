#include "Game.h"
int welcom_start_row = 0;
int map_start_row = 0;
int init_menu_start_row = 0;
int init_info_start_row = 0;
int menu_x = 0;
char* mapfile = "map.data";
extern List* mapList;
extern Player* loginPlayer;
extern initMenuStartRow;
extern initMainFrameRow;
/* 初始化玩家信息 */
Player players[] = {
    {1, "赵飞云", .loginName="linuslan", "123456", .money=50000, .level=1, .maxExp=20, .exp=0, .maxHp=100, .hp=100, .maxMp=50, .mp=50, .minAttack=5, .maxAttack=10, .minDefence=5, .maxDefence=10,
     .weapon={1, "生锈的铁剑", WEAPON, 1, .minAttack=5, .maxAttack=10, .price=100, .desc="新手专用"},
     .armor={2, "破旧的护甲", ARMOR, 2, .minDefence=5, .maxDefence=10, .price=500, .desc="新手专供"},
     .martial={3, "岳家军"}, .coord={0, 0},
     .bag={
         .count=1, .max=9,
        .props={
            {
            3, "木枪", WEAPON, .level=5, .minAttack=10, .maxAttack=15, .price=500, .stock=1, .desc="适合初入江湖的少侠"
            }
        }
     }},
    {2, "GM", .loginName="GM", "123456", .money=65535, .level=9999, .maxExp=65535, .exp=65535, .maxHp=65535, .maxMp=65535, .minAttack=65535, .maxAttack=65535, .minDefence=65535, .maxDefence=65535, .weapon={}, .armor={}, .martial={}, .coord={}, .bag={}}
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

/*测试用*/
Map maps2[16] = {
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
    },
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
};

Map secondMap1[6] = {
    {
        .id=1, .name="防具店", .fullName = "防", .coord={2, 2}, .endCoord={8, 5}, .desc=""
    },
    {
        .id=2, .name="道具店", .fullName="道", .coord={12, 2}, .endCoord={18, 5}, .desc=""
    },
    {
        .id=3, .name="杂货店", .fullName="杂", .coord={22, 2}, .endCoord={28, 5}, .desc=""
    },
    {
        .id=4, .name="武器店", .fullName="武", .coord={32, 2}, .endCoord={38, 5}, .desc=""
    },
    {
        .id=5, .name="县衙", .fullName="衙", .coord={20, 8}, .endCoord={30, 12}, .desc=""
    },
    {
        .id=6, .name="药店", .fullName="药", .coord={42, 2}, .endCoord={48, 5}, .desc=""
    }
};

Martial martial[] = {
    {
        1, "少林", {0, 1}, "天下武功出少林"
    },
    {
        2, "武当", {1, 0}, "灵山金顶"
    },
    {
        3, "岳家军", {0, 0}, "创始人岳飞"
    }
};

Monster monsters[] = {
    {
        1, "流氓", "不入流的角色", {0, 0}, .state=0, 1, 50, .minExp=1, .maxExp=5, .minAttack=1, .maxAttack=5, .minMoney=1, .maxMoney=5
    },
    {
        2, "地痞", "不入流的角色", {0, 0}, .state=0, 1, 50, .minExp=1, .maxExp=5, .minAttack=1, .maxAttack=5, .minMoney=1, .maxMoney=5
    },
    {
        3, "混混", "有一定的攻击力", {0, 0}, .state=0, 2, 100, .minExp=2, .maxExp=10, .minAttack=2, .maxAttack=10, .minMoney=2, .maxMoney=20
    },
    {
        4, "混混头目", "小群混混团体头目", {0, 0}, .state=0, 3, 200, .minExp=2, .maxExp=20, .minAttack=2, .maxAttack=20, .minMoney=2, .maxMoney=30
    },
    {
        5, "混混老大", "大群群混混团体领导人，带领几个混混头目", {0,0}, .state=0, 5, 300, .minExp=3, .maxExp=30, .minAttack=3, .maxAttack=30, .minMoney=3, .maxMoney=50
    }
};

void SavePlayers() {
    FILE* playerFile = NULL;
    char* playerFileName = "player.data";
    playerFile = fopen(playerFileName, "wb");
    if(!playerFile) {
        printf("创建玩家数据异常");
        return;
    }
    int size = sizeof(players) / sizeof(Player);
    for(int i = 0; i < size; i ++) {
        Player player = players[i];
        fwrite(&player, sizeof(Player), 1, playerFile);
    }
}

void ReadPlayer() {
    FILE* playerFile = NULL;
    char* playerFileName = "player.data";
    playerFile = fopen(playerFileName, "rb");
    if(!playerFile) {
        printf("初始化玩家数据异常");
        return;
    }
    Player* player = (Player*)malloc(sizeof(Player));
    printf("开始读数据\n");
    while(fread(player, sizeof(Player), 1, playerFile) > 0) {

    }
}

void SaveMap() {
    FILE* mapFile = NULL;
    char* mapFileName = "map.data";
    mapFile = fopen(mapFileName, "wb");
    int size = sizeof(maps2)/sizeof(Map);
    for(int i = 0; i < size; i ++) {
        Map map = maps2[i];
        fwrite(&map, sizeof(Map), 1, mapFile);
    }
}

void SaveSecondMap() {
    FILE* secondMapFile = NULL;
    char* secondMapName = "1.map";
    secondMapFile = fopen(secondMapName, "wb");
    int size = sizeof(secondMap1) / sizeof(Map);
    for(int i = 0; i < size; i ++) {
        Map map = secondMap1[i];
        //fputs(map.name, secondMapFile);
        fwrite(&map, sizeof(Map), 1, secondMapFile);
    }
    //fclose(secondMapFile);
}

void Init() {
    map_start_row = 3;
    init_info_start_row = map_start_row + sizeof(maps) / sizeof(maps[0]) + 1;
    init_menu_start_row = init_info_start_row + 11;
    loginPlayer = &players[0];
}

void RefreshMap(int x, int y) {
    int map_y = initMainFrameRow;
    int i, j;
    int size = sizeof(maps) / sizeof(maps[0]);
    int size2 = sizeof(maps[0]) / sizeof(Map);
    for(i = 0; i < size; i ++) {
        SetPosition(MARGIN_X+ROW_OFFSET_X, ++map_y);
        for(j = 0; j < size2; j ++) {
            Map map = maps[i][j];
            if(x == j && y == i) {
                SetSelectedColor();
            }
            printf("%-8s", map.name);
            ResetColor();
            printf("   ");
        }
        SetPosition(MARGIN_X+OFFSET_X, map_y++);
    }
    SetPosition(MARGIN_X, map_y);
}

void Move() {
    int x = loginPlayer->coord.X;
    int y = loginPlayer->coord.Y;
    int max_y = sizeof(maps)/sizeof(maps[0]);
    int max_x = sizeof(maps[0])/sizeof(Map);
    char key = 0;
    while(1) {
        key = getch();
        if(key == '0') {
            break;
        } else if(key == 13){
            EnterSecondMap();
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
                continue;
            }
            loginPlayer->coord.X = x;
            loginPlayer->coord.Y = y;
            RefreshMap(loginPlayer->coord.X, loginPlayer->coord.Y);
        }
    }
}

char menus[][50] = {"查看地图", "查看人物", "观察周围", "回门派", "购买装备"};
int size = sizeof(menus)/sizeof(menus[0]);
void InitGameMenu() {
    int info_start_row = initMainFrameRow;
    int menu_start_row = initMenuStartRow;
    Clear(++menu_start_row, 2, OFFSET_X-1);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, menu_start_row);
    printf("游戏菜单");
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-30, ++menu_start_row);
    for(int i = 0; i < size; i ++) {
        if(i == menu_x) {
            SetSelectedColor();
        }
        printf("%d、%s", i+1, menus[i]);
        ResetColor();
        printf("     ");
    }
    Clear(++info_start_row, MAIN_FRAME_ROW, OFFSET_X-1);
}

void SelectGameMenu() {
    int isSuccess = 0;
    char key = 0;
    while(1) {
        key = getch();
        if(key == 13) {
            isSuccess = ProcessGameMenu();
            if(isSuccess > 0) {
                break;
            }
        } else {
            if(key == VK_RIGHT || key == 77) {
                menu_x ++;
                if(menu_x >= size) {
                    menu_x = 0;
                }
            } else if(key == VK_LEFT || key == 75) {
                menu_x --;
                if(menu_x < 0) {
                    menu_x = size-1;
                }
            } else if(key != -32) {
                printf("输入错误");
                continue;
            }
        }
        InitGameMenu();
    }
}

void GetMapSize(int* x, int* y) {
    *y = sizeof(maps) / sizeof(maps[0]);
    *x = sizeof(maps[0]) / sizeof(Map);
}

int ProcessGameMenu() {
    if(menu_x == 0) {    //执行玩家属性展示
        RefreshMap(loginPlayer->coord.X, loginPlayer->coord.Y);
        Move();
    } else if(menu_x == 1) {
        ShowPlayer();
    } else if(menu_x == 2) {
        WatchAround(loginPlayer->coord.X, loginPlayer->coord.Y);
    } else if(menu_x == 3) {
        ShowStoreProps();
    }
    return 0;
}

void ShowPlayer() {
    int info_start_row = initMainFrameRow;
    Clear(++info_start_row, MAIN_FRAME_ROW, OFFSET_X-1);
    SetPosition(MARGIN_X+MIDDLE_OFFSET_X-3, info_start_row);
    printf("大侠资料");
    SetPosition(MARGIN_X+ROW_OFFSET_X, ++info_start_row);
    printf("姓名：%-10s级别：%d(%d/%d)\tHP：%d/%d\tMP：%d/%d\t金钱：%-10d", loginPlayer->name, loginPlayer->level, loginPlayer->exp,
            loginPlayer->maxExp, loginPlayer->hp, loginPlayer->maxHp, loginPlayer->mp, loginPlayer->maxMp, loginPlayer->money);
    SetPosition(MARGIN_X+ROW_OFFSET_X, ++info_start_row);
    printf("门派：%-10s武器：%s(最小攻击力%d，最大攻击力%d)", loginPlayer->martial.name,
            loginPlayer->weapon.name, loginPlayer->weapon.minAttack, loginPlayer->weapon.maxAttack);
    SetPosition(MARGIN_X+ROW_OFFSET_X, ++info_start_row);
    printf("防具：%s(最小防御力%d，最大防御力%d)", loginPlayer->armor.name, loginPlayer->armor.minDefence, loginPlayer->armor.maxDefence);
    SetPosition(MARGIN_X+ROW_OFFSET_X, ++info_start_row);
    printf("-------------------------------------背包-------------------------------------");
    SetPosition(MARGIN_X+ROW_OFFSET_X, ++info_start_row);
    if(loginPlayer->bag.count <= 0) {
        printf("当前背包空空如也，快意江湖岂能毫无准备");
    } else {
        int count = 0;
        for(int i = 0; i < loginPlayer->bag.count; i ++) {
            if(count >= loginPlayer->bag.count) {
                break;
            }
            Prop prop = loginPlayer->bag.props[i];
            if(i%4 == 0) {
                SetPosition(MARGIN_X+ROW_OFFSET_X, ++info_start_row);
            }
            printf("%d、%s(%d)\t", i+1, prop.name, prop.stock);
            count += prop.stock;
        }
    }
}

void WatchAround(int x, int y) {
    int info_start_row = initMainFrameRow;
    int len = 5;
    int targetIdx = 0;  //攻击的目标序号
    Monster* monsterArr = calloc(len, sizeof(Monster));
    int size = sizeof(monsters)/sizeof(Monster);
    int idx = 0;
    for(int i = 0; i < size; i ++) {
        Monster monster = monsters[i];
        if(monster.coord.X == x && monster.coord.Y == y) {
            if(idx >= len) {
                len = len + 5;
                Monster* temp = realloc(monsterArr, len);
                if(!temp) {
                    monsterArr = temp;
                }
            }

            Monster* newMonster = (Monster*)CreateMonster(&monster);
            if(!newMonster) {
                continue;
            }
            *(monsterArr + idx) = *(newMonster);
            idx ++;
        }
    }
    int row = info_start_row;
    info_start_row = RefreshMonster(monsterArr, &idx, row);
    while(1) {
        if(info_start_row < 0) {
            break;
        }
        if(targetIdx == -1) {
            info_start_row = RefreshMonster(monsterArr, &idx, row);
            if(info_start_row < 0) {
                break;
            }
        }
        SetPosition(MARGIN_X+7, info_start_row);
        printf(CLEAR_SPACE);
        SetPosition(MARGIN_X+7, info_start_row);
        fflush(stdin);
        printf("请选择攻击的目标或按0返回:");
        scanf("%d", &targetIdx);
        fflush(stdin);
        SetPosition(MARGIN_X+7, info_start_row);
        if(targetIdx == 0) {
            Clear(++info_start_row, MAIN_FRAME_ROW, OFFSET_X-1);
            break;
        }
        Monster* target = monsterArr + --targetIdx;
        Fight(loginPlayer, target, info_start_row);
        targetIdx = -1;
    }
    for(int i = 0; i < idx; i ++) {
        free(monsterArr+i);
    }
    monsterArr = NULL;
}

Monster* CreateMonster(const Monster* monster) {
    Monster* pMonster = (Monster*)malloc(sizeof(Monster));
    if(pMonster == NULL) {
        return NULL;
    }
    strcpy(pMonster->name, monster->name);
    pMonster->coord = monster->coord;
    strcpy(pMonster->desc, monster->desc);
    pMonster->hp = monster->hp;
    pMonster->id = monster->id;
    pMonster->level = monster->level;
    pMonster->maxAttack = monster->maxAttack;
    pMonster->maxExp = monster->maxExp;
    pMonster->maxMoney = monster->maxMoney;
    pMonster->minAttack = monster->minAttack;
    pMonster->minExp = monster->minExp;
    pMonster->minMoney = monster->minMoney;
    pMonster->state = monster->state;
    return pMonster;
}

int RefreshMonster(Monster* monsterArr, int* monsterCount, int info_start_row) {
    Clear(++info_start_row, MAIN_FRAME_ROW, OFFSET_X-1);
    SetPosition(MARGIN_X+35, info_start_row++);
    printf("大侠看了看四周");
    SetPosition(MARGIN_X+7, info_start_row++);
    if(*monsterCount <= 0) {
        printf("这是一个鸟不生蛋的地方，连个怪都没有");
        return -1;
    }
    Monster* monster = NULL;
    int count = 0;
    int j = 0;
    for(int i = 0; i < *monsterCount; i ++) {
        monster = monsterArr+i;
        if(monster->state == 1) {
            j = i;
            while(j < *monsterCount) {
                free(monster);
                *(monsterArr + j) = *(monsterArr + ++j);
            }
            continue;
        }
        count ++;
    }
    *monsterCount = count;
    monster = NULL;
    for(int i = 0; i < count; i ++) {
        monster = monsterArr + i;
        if(i != 0 && i % 4 == 0) {
            SetPosition(MARGIN_X+7, info_start_row++);
        }
        printf("%d、%s(%d级)\t", i + 1, monster->name, monster->level);
    }
    return info_start_row;
}

void Fight(Player* player, Monster* monster, int row) {
    time_t seed;
    int isFinished = 1;
    char confirm = 'N';
    int fightCount = 0;
    while(player->hp > 0 && monster->hp > 0) {
        SetPosition(MARGIN_X+7, row);
        printf(CLEAR_SPACE);
        SetPosition(MARGIN_X+7, row);
        if(player->mp <= 0 && toupper(confirm) == 'N') {
            printf("大侠内力值不够了，快逃命吧！(按0结束战斗)");
            scanf("%d", &isFinished);
            fflush(stdin);
            if(isFinished == 0) {
                break;
            } else {
                SetPosition(MARGIN_X+7, row);
                printf(CLEAR_SPACE);
                SetPosition(MARGIN_X+7, row);
                printf("您确定继续战斗？(y/n)");
                fflush(stdin);
                scanf("%c", &confirm);
                fflush(stdin);
                if(toupper(confirm) == 'N') {
                    break;
                } else {
                    SetPosition(MARGIN_X+7, row);
                }
            }
        }
        srand(time(&seed));
        int monsterAttack = rand() % (monster->maxAttack-monster->minAttack+1) + monster->minAttack;
        int playerAttack = 0;
        if(player->mp > 0) {
            playerAttack = rand() %(player->maxAttack-player->minAttack+1)+player->minAttack;
        }
        player->hp -= monsterAttack;
        player->mp -= 5;
        monster->hp -= playerAttack;
        if(player->hp <= 0) {
            printf("技不如人，来年又是一条好汉(回车结束)");
            getch();
            fflush(stdin);
            SetPosition(MARGIN_X+7, row);
            printf(CLEAR_SPACE);
            break;
        }
        if(monster->hp <= 0) {
            int exp = rand()%(monster->maxExp-monster->minExp+1) + monster->minExp;
            int money = rand() %(monster->maxMoney-monster->minMoney+1) + monster->minMoney;
            printf("大侠好身手，轻松赢得胜利，获得经验%d，金钱%d(回车结束)", exp, money);
            player->exp += exp;
            player->money += money;
            monster->state=1;
            getch();
            fflush(stdin);
            SetPosition(MARGIN_X+7, row);
            printf(CLEAR_SPACE);
            break;
        }
        fightCount ++;
        printf("第%d轮战斗，大侠攻击力:%d，剩余HP:%d，剩余MP:%d，%s攻击力:%d，剩余HP:%d", fightCount, playerAttack, player->hp,
               player->mp, monster->name, monsterAttack, monster->hp);
        Sleep(500);
    }
}

int RefreshProps(int offset) {
    int infoStartRow = initMainFrameRow;
    Clear(++infoStartRow, MAIN_FRAME_ROW, OFFSET_X-1);

    SetPosition(MARGIN_X+45, infoStartRow++);
    printf("走过路过，不要错过");
    Prop prop;
    int size = sizeof(props) / sizeof(Prop);
    for(int i = 0; i < size; i ++) {
        prop = props[i];
        if(i % 4 == 0) {
            SetPosition(offset, infoStartRow++);
        }
        printf("%d、%s(%d级，库存:%d)\t", i + 1, prop.name, prop.level, prop.stock);
    }
    return infoStartRow;
}

/* 展示商店的商品 */
void ShowStoreProps() {
    int offset = MARGIN_X+7;
    int size = sizeof(props) / sizeof(Prop);
    int infoStartRow = RefreshProps(offset);
    int targetId = 0;
    while(1) {
        SetPosition(offset, infoStartRow);
        printf(CLEAR_SPACE);
        SetPosition(offset, infoStartRow);
        printf("请选择物品编号(0退出):");
        scanf("%d", &targetId);
        if(targetId == 0) {
            int infoStartRow = initMainFrameRow;
            Clear(++infoStartRow, MAIN_FRAME_ROW, OFFSET_X-1);
            break;
        } else {
            targetId--;
            if(targetId < 0 || targetId >= size) {
                SetPosition(offset, infoStartRow);
                printf(CLEAR_SPACE);
                SetPosition(offset, infoStartRow);
                printf("输入无效");
                getch();
                fflush(stdin);
                continue;
            }
            Prop* pProp = &props[targetId];
            StoreTrade(loginPlayer, pProp, offset, infoStartRow);
            infoStartRow = RefreshProps(offset);
        }
    }
}

/* 购买道具 */
void StoreTrade(Player* player, Prop* prop, int offset, int row) {
    if(prop->stock <= 0) {
        SetPosition(offset, row);
        printf(CLEAR_SPACE);
        SetPosition(offset, row);
        printf("商品库存不足");
        getch();
        fflush(stdin);
        return;
    }
    if(player->bag.count >= player->bag.max) {
        SetPosition(offset, row);
        printf(CLEAR_SPACE);
        SetPosition(offset, row);
        printf("您的背包空间不足");
        getch();
        fflush(stdin);
        return;
    }
    if(player->money < prop->price) {
        SetPosition(offset, row);
        printf(CLEAR_SPACE);
        SetPosition(offset, row);
        printf("您的金钱不足");
        getch();
        fflush(stdin);
        return;
    }
    Prop* bought;
    int i = 0;
    for(; i < player->bag.count; i ++) {
        bought = &player->bag.props[i];
        if(bought->id == prop->id) {
            bought->stock++;
            break;
        }
    }
    if(i == player->bag.count) {
        Prop* newProp = &player->bag.props[i];
        newProp->id = prop->id;
        strcpy(newProp->desc, prop->desc);
        newProp->level = prop->level;
        newProp->maxAttack = prop->maxAttack;
        newProp->maxDefence = prop->maxDefence;
        newProp->minAttack = prop->minAttack;
        newProp->minDefence = prop->minDefence;
        strcpy(newProp->name, prop->name);
        newProp->price = prop->price;
        newProp->propType = prop->propType;
        newProp->stock = 1;
    }
    player->bag.count ++;
    player->money -= prop->price;
    prop->stock --;
}

/* 初始化二级目录 */
void InitSecondMap() {
    Map** maps = NULL;
    int x = loginPlayer->coord.X;
    int y = loginPlayer->coord.Y;
    FILE* file = fopen(mapfile, "rb");
    Map* map = (Map*)malloc(sizeof(Map));
    while(1<=fread(map, sizeof(Map), 1, file)) {
        if(map->coord.X==x && map->coord.Y==y) {
            break;
        }
    }
    fclose(file);
    file = NULL;
    if(NULL != mapList && mapList->size > 0) {
        int size = mapList->size;
        for(int i = 0; i < size; i ++) {
            Map* map = mapList->object + i;
            free(map);
        }
        free(mapList);
    }
    mapList = NULL;
    mapList = (List*)malloc(sizeof(List));
    if(map->coord.X == x && map->coord.Y == y) {
        char id[2] = {'0'+map->id, '\0'};
        char* secondMapFile = strcat(id, ".map");
        file = fopen("1.map", "rb");
        int i = 0;

        while(1<=fread(map, sizeof(Map), 1, file)) {
            Map* newMap = (Map*)malloc(sizeof(Map));    //重新创建一块内存，如果用map，则只是同一块内存被修改不同的值，最后的值即为最后一个
            memcpy(newMap, map, sizeof(Map));
            i++;
            if(NULL == maps) {
                maps = (Map**)malloc(sizeof(Map*));
            } else {
                Map** temp = (Map**)realloc(maps, i*sizeof(Map*));
                maps = temp;
            }
            *(maps+(i-1)) = newMap;

        }
        mapList->object=maps;
        mapList->size = i;
    }
}

void RefreshSecondMap() {
    int row = initMainFrameRow;
    int size = mapList->size;
    if(size < 1) {
        return;
    }
    Clear(++row, MAIN_FRAME_ROW, OFFSET_X-1);
    Map** maps = mapList->object;
    //draw building
    for(int i = 0; i < size; i ++) {
        Map* map = *(maps+i);
        int start_x = map->coord.X;
        int start_y = map->coord.Y;
        int end_x = map->endCoord.X;
        int end_y = map->endCoord.Y;
        int middle_x = (int)(end_x-start_x)/2+start_x-1;
        int middle_y = (int)(end_y-start_y)/2+start_y;
        for(int j = start_x; j < end_x; j ++) {
            SetPosition(MARGIN_X+j, row+start_y);
            SetSelectedColor();
            printf(" ");
            for(int n = start_y; n < end_y; n ++) {
                SetPosition(MARGIN_X+j, row+n);
                printf(" ");
            }
        }
        SetPosition(MARGIN_X+middle_x, row+middle_y);
        printf("%s", map->fullName);
    }
}

void EnterSecondMap() {
    InitSecondMap();
    RefreshSecondMap();
}

